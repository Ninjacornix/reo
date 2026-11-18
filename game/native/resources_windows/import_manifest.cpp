#include "import_manifest.hpp"

#ifndef _WIN32
#error import_manifest.cpp requires Windows.Data.Json
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <roapi.h>
#include <winstring.h>
// LLVM/MinGW 20251216 gives BYTE and WinRT boolean the same C++ type, but its
// windows.foundation.h emits both IReference specializations. This unused
// interface is suppressed locally; the JSON interfaces and ABI are untouched.
// GCC's newer MinGW headers do not need the workaround. No SDK file is edited.
#if defined(__clang__) && defined(__MINGW32__)
#ifndef ____FIReference_1_boolean_INTERFACE_DEFINED__
#define ____FIReference_1_boolean_INTERFACE_DEFINED__
#endif
#endif
#include <windows.data.json.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <set>
#include <sstream>
#include <string_view>
#include <utility>

namespace reo::native::resources::win32 {
namespace {
namespace Json = ABI::Windows::Data::Json;
using ValueVector = ABI::Windows::Foundation::Collections::IVector<Json::IJsonValue*>;
using ValueMap = ABI::Windows::Foundation::Collections::IMap<HSTRING, Json::IJsonValue*>;
constexpr std::string_view elf_hex = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46";

[[noreturn]] void fail(const std::string& reason) {
    throw ImportManifestError("import manifest: " + reason);
}
void require(bool condition, const std::string& reason) {
    if (!condition) fail(reason);
}
void checked(HRESULT result, std::string_view operation) {
    if (FAILED(result)) {
        std::ostringstream message;
        message << operation << " (HRESULT 0x" << std::hex << std::setw(8)
                << std::setfill('0') << static_cast<std::uint32_t>(result) << ')';
        fail(message.str());
    }
}

template<class T> class Com {
    T* value_ = nullptr;
public:
    Com() = default;
    ~Com() { if (value_) value_->Release(); }
    Com(const Com&) = delete;
    Com& operator=(const Com&) = delete;
    Com(Com&& other) noexcept : value_(std::exchange(other.value_, nullptr)) {}
    Com& operator=(Com&& other) noexcept {
        if (this != &other) {
            if (value_) value_->Release();
            value_ = std::exchange(other.value_, nullptr);
        }
        return *this;
    }
    T* operator->() const noexcept { return value_; }
    T** put() noexcept { return &value_; }
    template<class U> Com<U> as() const {
        Com<U> result;
        checked(value_->QueryInterface(__uuidof(U), reinterpret_cast<void**>(result.put())),
                "required Windows JSON interface unavailable");
        return result;
    }
};

class Apartment {
    bool balanced_ = false;
public:
    Apartment() {
        auto result = RoInitialize(RO_INIT_MULTITHREADED);
        // An existing STA is retained, with our one successful initialization
        // balanced below. Never uninitialize a failed changed-mode attempt.
        if (result == RPC_E_CHANGED_MODE) result = RoInitialize(RO_INIT_SINGLETHREADED);
        checked(result, "Windows Runtime initialization failed");
        balanced_ = true;
    }
    ~Apartment() { if (balanced_) RoUninitialize(); }
    Apartment(const Apartment&) = delete;
    Apartment& operator=(const Apartment&) = delete;
};

class String {
    HSTRING value_ = nullptr;
public:
    String() = default;
    explicit String(std::wstring_view text) {
        require(text.size() <= std::numeric_limits<UINT32>::max(), "string exceeds OS bounds");
        checked(WindowsCreateString(text.data(), static_cast<UINT32>(text.size()), &value_),
                "Windows string allocation failed");
    }
    ~String() { WindowsDeleteString(value_); }
    String(const String&) = delete;
    String& operator=(const String&) = delete;
    HSTRING get() const noexcept { return value_; }
    HSTRING* put() noexcept { return &value_; }
    std::wstring_view view() const noexcept {
        UINT32 size = 0;
        const auto* text = WindowsGetStringRawBuffer(value_, &size);
        return {text, size};
    }
};

std::wstring from_utf8(std::span<const std::uint8_t> bytes) {
    require(bytes.size() <= static_cast<std::size_t>(std::numeric_limits<int>::max()), "UTF-8 exceeds OS bounds");
    const auto* data = reinterpret_cast<const char*>(bytes.data());
    const auto size = static_cast<int>(bytes.size());
    const int count = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data, size, nullptr, 0);
    require(count > 0, "input must be valid UTF-8");
    std::wstring result(static_cast<std::size_t>(count), L'\0');
    require(MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, data, size, result.data(), count) == count,
            "UTF-8 conversion failed");
    return result;
}
std::string to_utf8(std::wstring_view value) {
    if (value.empty()) return {};
    require(value.size() <= static_cast<std::size_t>(std::numeric_limits<int>::max()), "string exceeds OS bounds");
    const auto size = static_cast<int>(value.size());
    const int count = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(), size,
                                          nullptr, 0, nullptr, nullptr);
    require(count > 0, "JSON string contains invalid Unicode");
    std::string result(static_cast<std::size_t>(count), '\0');
    require(WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(), size,
                               result.data(), count, nullptr, nullptr) == count,
            "JSON string UTF-8 conversion failed");
    return result;
}

void lexical_admission(std::span<const std::uint8_t> bytes) {
    // This is a restricted-domain filter, not a structural JSON parser. Strings
    // are skipped with their escapes; Windows.Data.Json owns syntax, values and
    // fields. It prevents rounded doubles from admitting fractional/exponent
    // spellings and bounds nesting before invoking the OS parser.
    bool in_string = false, escaped = false;
    unsigned nesting = 0;
    for (std::size_t i = 0; i < bytes.size(); ++i) {
        const auto c = bytes[i];
        if (in_string) {
            if (escaped) escaped = false;
            else if (c == '\\') escaped = true;
            else if (c == '"') in_string = false;
            continue;
        }
        if (c == '"') { in_string = true; continue; }
        if (c == '{' || c == '[') {
            require(++nesting <= 32, "JSON nesting exceeds 32 levels");
        } else if ((c == '}' || c == ']') && nesting) {
            --nesting;
        }
        if ((c >= '0' && c <= '9') || c == '-' || c == '+') {
            std::size_t end = i;
            while (end < bytes.size() && bytes[end] != ',' && bytes[end] != '}' && bytes[end] != ']' &&
                   bytes[end] != ' ' && bytes[end] != '\t' && bytes[end] != '\r' && bytes[end] != '\n') {
                require(bytes[end] >= '0' && bytes[end] <= '9',
                        "numbers must use unsigned decimal integer notation");
                ++end;
            }
            require(end - i <= 20, "integer token exceeds 20 decimal digits");
            i = end - 1;
        }
    }
}

Com<Json::IJsonValue> field(const Com<Json::IJsonObject>& object, std::wstring_view name) {
    String key(name);
    Com<Json::IJsonValue> result;
    checked(object->GetNamedValue(key.get(), result.put()), "required field missing or inaccessible: " + to_utf8(name));
    return result;
}
std::wstring text(const Com<Json::IJsonValue>& value, std::string_view name, std::size_t max_units) {
    String result;
    checked(value->GetString(result.put()), std::string(name) + " must be a string");
    require(result.view().size() <= max_units, std::string(name) + " exceeds string bound");
    return std::wstring(result.view());
}
std::uint32_t integer(const Com<Json::IJsonValue>& value, std::string_view name) {
    double number = 0;
    checked(value->GetNumber(&number), std::string(name) + " must be a number");
    require(std::isfinite(number) && number >= 0 &&
            number <= static_cast<double>(std::numeric_limits<std::uint32_t>::max()) &&
            std::floor(number) == number, std::string(name) + " must be an exact unsigned 32-bit integer");
    return static_cast<std::uint32_t>(number);
}
Digest hash(std::wstring_view value, std::string_view name) {
    require(value.size() == 64, std::string(name) + " must contain 64 hexadecimal digits");
    const auto digit = [name](wchar_t c) -> std::uint8_t {
        if (c >= L'0' && c <= L'9') return static_cast<std::uint8_t>(c - L'0');
        if (c >= L'a' && c <= L'f') return static_cast<std::uint8_t>(c - L'a' + 10);
        if (c >= L'A' && c <= L'F') return static_cast<std::uint8_t>(c - L'A' + 10);
        fail(std::string(name) + " contains a non-hexadecimal character");
    };
    Digest result{};
    for (std::size_t i = 0; i < result.size(); ++i)
        result[i] = static_cast<std::uint8_t>((digit(value[i * 2]) << 4) | digit(value[i * 2 + 1]));
    return result;
}
std::wstring upper(std::wstring_view input) {
    const auto size = static_cast<int>(input.size());
    const int count = LCMapStringEx(LOCALE_NAME_INVARIANT, LCMAP_UPPERCASE, input.data(), size,
                                     nullptr, 0, nullptr, nullptr, 0);
    require(count > 0, "path case mapping failed");
    std::wstring result(static_cast<std::size_t>(count), L'\0');
    require(LCMapStringEx(LOCALE_NAME_INVARIANT, LCMAP_UPPERCASE, input.data(), size,
                          result.data(), count, nullptr, nullptr, 0) == count,
            "path case mapping failed");
    return result;
}
bool device_name(std::wstring_view component) {
    auto base = upper(component.substr(0, component.find(L'.')));
    while (!base.empty() && (base.back() == L' ' || base.back() == L'.')) base.pop_back();
    if (base == L"CON" || base == L"PRN" || base == L"AUX" || base == L"NUL" ||
        base == L"CLOCK$" || base == L"CONIN$" || base == L"CONOUT$") return true;
    if (base.size() == 4 && (base.starts_with(L"COM") || base.starts_with(L"LPT"))) {
        const auto c = base.back();
        return (c >= L'0' && c <= L'9') || c == L'\u00b9' || c == L'\u00b2' || c == L'\u00b3';
    }
    return false;
}
std::pair<std::string, std::wstring> path_name(std::wstring name) {
    require(!name.empty() && name.size() <= max_relative_name_bytes, "file Name is empty or too long");
    std::replace(name.begin(), name.end(), L'\\', L'/');
    std::size_t begin = 0;
    while (begin <= name.size()) {
        const auto slash = name.find(L'/', begin);
        const auto part = std::wstring_view(name).substr(begin, slash == std::wstring::npos ? slash : slash - begin);
        require(!part.empty() && part != L"." && part != L".." && part.size() <= 255,
                "file Name has an unsafe path component");
        require(part.back() != L'.' && part.back() != L' ', "file Name has a trailing-dot/space alias");
        for (const wchar_t c : part) {
            require(c > 31 && !(c >= 127 && c <= 159) &&
                    !(c >= 0x202a && c <= 0x202e) && !(c >= 0x2066 && c <= 0x2069) &&
                    c != 0xfeff && std::wstring_view(L"<>:\"|?*~").find(c) == std::wstring_view::npos,
                    "file Name contains a control, reserved character or short-name alias");
        }
        require(!device_name(part), "file Name uses a Win32 device alias");
        if (slash == std::wstring::npos) break;
        begin = slash + 1;
    }
    auto utf8 = to_utf8(name);
    require(utf8.size() <= max_relative_name_bytes, "file Name exceeds UTF-8 byte bound");
    return {std::move(utf8), upper(name)};
}
} // namespace

ImportManifest parse_import_manifest(std::span<const std::uint8_t> utf8) {
    require(!utf8.empty() && utf8.size() <= max_manifest_bytes, "input is empty or exceeds 8 MiB");
    require(std::find(utf8.begin(), utf8.end(), std::uint8_t{0}) == utf8.end(), "raw NUL in JSON input");
    if (utf8.size() >= 3 && utf8[0] == 0xef && utf8[1] == 0xbb && utf8[2] == 0xbf) utf8 = utf8.subspan(3);
    require(!utf8.empty(), "input contains only a UTF-8 BOM");
    lexical_admission(utf8);
    String document(from_utf8(utf8));
    Apartment apartment;
    String class_name(L"Windows.Data.Json.JsonValue");
    Com<Json::IJsonValueStatics> factory;
    checked(RoGetActivationFactory(class_name.get(), __uuidof(Json::IJsonValueStatics),
                                   reinterpret_cast<void**>(factory.put())), "Windows JSON activation failed");
    Com<Json::IJsonValue> root;
    checked(factory->Parse(document.get(), root.put()), "invalid JSON document");
    Com<Json::IJsonObject> object;
    checked(root->GetObject(object.put()), "root must be an object");
    ImportManifest result;
    result.version = integer(field(object, L"Version"), "Version");
    require(result.version == 1 || result.version == 2, "only import Version 1 or 2 is supported");
    result.game = to_utf8(text(field(object, L"Game"), "Game", 16));
    require(result.game == "file1", "only File #1 imports are supported");
    result.elf_sha256 = hash(text(field(object, L"ElfSha256"), "ElfSha256", 64), "ElfSha256");
    const auto expected = hash(std::wstring(elf_hex.begin(), elf_hex.end()), "pinned ELF");
    require(result.elf_sha256 == expected, "unsupported File #1 executable identity");
    Com<Json::IJsonArray> array;
    checked(field(object, L"Files")->GetArray(array.put()), "Files must be an array");
    auto values = array.as<ValueVector>();
    UINT32 count = 0;
    checked(values->get_Size(&count), "Files size unavailable");
    require(count > 0 && count <= max_imported_files, "Files must contain 1..65536 rows");
    result.files.reserve(count);
    std::set<std::wstring> names;
    bool found_elf = false;
    for (UINT32 i = 0; i < count; ++i) {
        Com<Json::IJsonObject> file;
        checked(array->GetObjectAt(i, file.put()), "each Files row must be an object");
        auto [name, key] = path_name(text(field(file, L"Name"), "Name", max_relative_name_bytes));
        require(names.insert(key).second, "duplicate case-insensitive file Name");
        ImportedFile entry{std::move(name), integer(field(file, L"Length"), "Length"),
                           hash(text(field(file, L"Sha256"), "Sha256", 64), "Sha256")};
        if (key == L"SLUS_207.65") {
            require(entry.length > 0 && entry.sha256 == expected, "ELF file row identity is inconsistent");
            found_elf = true;
        }
        result.files.push_back(std::move(entry));
    }
    require(found_elf, "Files must include the pinned SLUS_207.65 row");
    for (const auto& name : names) {
        for (auto slash = name.find(L'/'); slash != std::wstring::npos; slash = name.find(L'/', slash + 1))
            require(!names.contains(name.substr(0, slash)), "file Name conflicts with a parent file");
    }
    const auto map = object.as<ValueMap>();
    String source_key(L"Source");
    boolean has_source = false;
    checked(map->HasKey(source_key.get(), &has_source), "Source provenance lookup failed");
    if (has_source) {
        auto source = text(field(object, L"Source"), "Source", 32768);
        result.source = to_utf8(source);
    }
    return result;
}

} // namespace reo::native::resources::win32

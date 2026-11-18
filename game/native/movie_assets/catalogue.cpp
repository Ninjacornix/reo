#include "catalogue.hpp"
#include "../resources_windows/pinned_file.hpp"
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <roapi.h>
#include <winstring.h>
#if defined(__clang__) && defined(__MINGW32__)
#ifndef ____FIReference_1_boolean_INTERFACE_DEFINED__
#define ____FIReference_1_boolean_INTERFACE_DEFINED__
#endif
#endif
#include <windows.data.json.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stdexcept>
#include <utility>

namespace reo::native::movie_assets {
namespace {
namespace Json=ABI::Windows::Data::Json;
namespace files=resources::win32;
using Values=ABI::Windows::Foundation::Collections::IVector<Json::IJsonValue*>;
void require(bool condition,const char* reason){if(!condition)throw std::runtime_error(std::string("Native movie assets: ")+reason);}
void checked(HRESULT status,const char* reason){require(SUCCEEDED(status),reason);}
template<class T>struct Com {
    T* p{};~Com(){if(p)p->Release();}
    Com()=default;Com(const Com&)=delete;Com& operator=(const Com&)=delete;
    Com(Com&& other)noexcept:p(std::exchange(other.p,nullptr)){}
    T* operator->()const{return p;}
};
struct String {
    HSTRING value{};String()=default;explicit String(std::wstring_view s){checked(WindowsCreateString(s.data(),static_cast<UINT32>(s.size()),&value),"JSON string allocation");}
    ~String(){WindowsDeleteString(value);}String(const String&)=delete;
    std::wstring_view text()const{UINT32 n{};const auto* p=WindowsGetStringRawBuffer(value,&n);return{p,n};}
};
struct Apartment {
    Apartment(){auto status=RoInitialize(RO_INIT_MULTITHREADED);if(status==RPC_E_CHANGED_MODE)status=RoInitialize(RO_INIT_SINGLETHREADED);checked(status,"JSON apartment");}
    ~Apartment(){RoUninitialize();}
};
Com<Json::IJsonValue> field(const Com<Json::IJsonObject>& object,std::wstring_view name){String key(name);Com<Json::IJsonValue> value;checked(object->GetNamedValue(key.value,&value.p),"Missing movie metadata field");return value;}
std::string text(const Com<Json::IJsonObject>& object,std::wstring_view name,std::size_t limit=256){String string;checked(field(object,name)->GetString(&string.value),"Movie metadata must be text");const auto value=string.text();require(!value.empty()&&value.size()<=limit,"Movie metadata text length");std::string out;for(auto ch:value){require(ch>=32&&ch<127,"Movie metadata must be ASCII");out+=static_cast<char>(ch);}return out;}
std::uint32_t integer(const Com<Json::IJsonObject>& object,std::wstring_view name){double n{};checked(field(object,name)->GetNumber(&n),"Movie metadata must be numeric");require(std::isfinite(n)&&n>=0&&n<=0x7fffffff&&std::floor(n)==n,"Movie metadata integer bounds");return static_cast<std::uint32_t>(n);}
bool boolean_field(const Com<Json::IJsonObject>& object,std::wstring_view name){boolean value{};checked(field(object,name)->GetBoolean(&value),"Movie metadata must be boolean");return value!=0;}
files::Digest digest(std::string_view text){require(text.size()==64,"Movie asset hash length");auto hex=[](char c){require((c>='0'&&c<='9')||(c>='a'&&c<='f'),"Movie asset hash characters");return static_cast<unsigned>(c<='9'?c-'0':c-'a'+10);};files::Digest out{};for(unsigned i=0;i<out.size();++i)out[i]=static_cast<std::uint8_t>(hex(text[2*i])*16+hex(text[2*i+1]));return out;}
std::wstring read_index(const std::filesystem::path& path) {
    struct File {HANDLE handle{INVALID_HANDLE_VALUE};~File(){if(handle!=INVALID_HANDLE_VALUE)CloseHandle(handle);}} file;
    file.handle=CreateFileW(path.c_str(),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
    require(file.handle!=INVALID_HANDLE_VALUE,"Open prepared movie catalogue");LARGE_INTEGER size{};
    require(GetFileSizeEx(file.handle,&size)&&size.QuadPart>0&&size.QuadPart<=2*1024*1024,"Movie catalogue size");
    std::string bytes(static_cast<std::size_t>(size.QuadPart),'\0');DWORD got{};
    require(ReadFile(file.handle,bytes.data(),static_cast<DWORD>(bytes.size()),&got,nullptr)&&got==bytes.size(),"Read movie catalogue");
    require(bytes.find('\0')==std::string::npos,"NUL in movie catalogue");
    const auto count=MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,bytes.data(),static_cast<int>(bytes.size()),nullptr,0);require(count>0,"Movie catalogue UTF-8");
    std::wstring out(static_cast<std::size_t>(count),L'\0');require(MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,bytes.data(),static_cast<int>(bytes.size()),out.data(),count)==count,"Movie catalogue Unicode conversion");return out;
}
}
Asset::Asset(std::string key,std::filesystem::path path,std::uint32_t frames,std::uint64_t bytes,std::shared_ptr<const resources::win32::PinnedFile> lease)
    :key_(std::move(key)),path_(std::move(path)),frames_(frames),bytes_(bytes),lease_(std::move(lease)){}
std::shared_ptr<const Catalogue> Catalogue::open(const std::filesystem::path& folder,bool complete) {
    const auto root=std::filesystem::canonical(folder);const auto input=read_index(root/L"movies.json");
    Apartment apartment;String class_name(L"Windows.Data.Json.JsonValue"),document(input);
    Com<Json::IJsonValueStatics> factory;checked(RoGetActivationFactory(class_name.value,__uuidof(Json::IJsonValueStatics),reinterpret_cast<void**>(&factory.p)),"JSON factory");
    Com<Json::IJsonValue> value;checked(factory->Parse(document.value,&value.p),"Parse movie catalogue");Com<Json::IJsonObject> object;checked(value->GetObject(&object.p),"Movie catalogue object");
    require(integer(object,L"format")==1&&text(object,L"game")=="file1"&&text(object,L"profile")=="file1-h264-cfr-crf18-v1"&&
        text(object,L"source_elf_sha256")=="06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46","Unsupported prepared movie catalogue");
    const auto all=boolean_field(object,L"complete_catalogue");require(!complete||all,"A complete native movie cache is required");
    Com<Json::IJsonArray> array;checked(field(object,L"movies")->GetArray(&array.p),"Movie list");Com<Values> values;checked(array->QueryInterface(__uuidof(Values),reinterpret_cast<void**>(&values.p)),"Movie list interface");UINT32 count{};checked(values->get_Size(&count),"Movie list size");
    require(count>0&&count<=4096&&count==integer(object,L"prepared")&&(!all||count==201),"Movie list count");
    auto result=std::shared_ptr<Catalogue>(new Catalogue);result->entries_.reserve(count);
    std::map<std::string,std::shared_ptr<const Asset>> pinned;std::map<std::string,std::string> hashes;std::set<std::string> labels;
    for(UINT32 i=0;i<count;++i) {
        Com<Json::IJsonObject> row;checked(array->GetObjectAt(i,&row.p),"Movie asset object");
        const auto key=text(row,L"source_key"),native_hash=text(row,L"sha256"),label=text(row,L"source_name"),name=text(row,L"file");
        (void)digest(key);const auto expected=digest(native_hash);require(name==key+".mp4","Movie filename must match its resource key");require(labels.insert(label).second,"Duplicate movie label");
        const auto bytes=integer(row,L"bytes"),frames=integer(row,L"frames");require(bytes>=32&&frames>0,"Empty movie asset");
        auto found=pinned.find(key);std::shared_ptr<const Asset> asset;
        if(found!=pinned.end()){asset=found->second;require(asset->bytes()==bytes&&asset->frames()==frames&&hashes[key]==native_hash,"Conflicting duplicate movie key");}
        else {
            const auto path=root/name;auto opened=files::PinnedFile::open_verified(path,bytes,expected);
            require(opened.status==files::PinnedStatus::ok&&bool(opened.file),"Prepared movie file identity/hash mismatch");
            asset=std::shared_ptr<const Asset>(new Asset(key,path,frames,bytes,std::move(opened.file)));pinned.emplace(key,asset);hashes.emplace(key,native_hash);
        }
        result->entries_.push_back({label,std::move(asset),integer(row,L"member_index")});
    }
    return result;
}
std::shared_ptr<const Asset> Catalogue::find(std::string_view key)const noexcept{for(const auto& row:entries_)if(row.asset->key()==key)return row.asset;return {};}
std::shared_ptr<const Asset> Catalogue::find_label(std::string_view label)const noexcept{for(const auto& row:entries_)if(row.label==label)return row.asset;return {};}
}

#pragma once
#include <string>
#include <string_view>
#include <regex>
#include <stdexcept>
#include <cctype>
#include <vector>
namespace ps2recomp::source_guard {
inline bool ident(char c) {
    return std::isalnum(static_cast<unsigned char>(c)) || c == '_';
}
inline size_t balanced(const std::string& s, size_t open, char left, char right) {
    unsigned depth = 0;
    for (size_t at = open; at < s.size(); ++at) {
        if (s[at] == left)
            ++depth;
        else if (s[at] == right && !--depth)
            return at + 1;
    }
    throw std::runtime_error("Unclosed source field expression");
}
inline std::string trim(std::string value) {
    size_t first = value.find_first_not_of(" \r\n\t"), last = value.find_last_not_of(" \r\n\t");
    return first == std::string::npos ? "" : value.substr(first, last - first + 1);
}
inline std::string maskedWrites(std::string text) {
    // Replace only a destination-preserving blend. Source-mask blends with a
    // different old operand stay reads and retain their original semantics.
    const std::regex pattern(R"((ctx->(?:vu0_vf\[[^\]]+\]|vu0_acc))\s*=\s*_mm_blendv_ps\()");
    std::smatch match;
    size_t from = 0;
    while (std::regex_search(text.cbegin() + from, text.cend(), match, pattern)) {
        size_t begin = from + match.position(), open = begin + match.length() - 1,
               end = balanced(text, open, '(', ')');
        std::vector<std::string> args;
        size_t part = open + 1;
        unsigned round = 0, square = 0;
        for (size_t at = part; at < end - 1; ++at) {
            if (text[at] == '(')
                ++round;
            else if (text[at] == ')')
                --round;
            else if (text[at] == '[')
                ++square;
            else if (text[at] == ']')
                --square;
            else if (text[at] == ',' && !round && !square) {
                args.push_back(trim(text.substr(part, at - part)));
                part = at + 1;
            }
        }
        args.push_back(trim(text.substr(part, end - 1 - part)));
        const std::string field = match[1];
        if (args.size() == 3 && args[0] == field) {
            std::string replacement = "reo_source_instrumentation::writeMaskedVector(rdram,*ctx,&" +
                                      field + "," + args[1] + "," + args[2] + ")";
            text.replace(begin, end - begin, replacement);
            from = begin + replacement.size();
        } else
            from = end;
    }
    return text;
}
inline std::string fields(const std::string& input) {
    std::string out;
    out.reserve(input.size() * 2);
    size_t at = 0;
    while (at < input.size()) {
        if (input.compare(at, 2, "//") == 0) {
            size_t end = input.find('\n', at);
            if (end == std::string::npos)
                end = input.size();
            out.append(input, at, end - at);
            at = end;
            continue;
        }
        if (input.compare(at, 2, "/*") == 0) {
            size_t end = input.find("*/", at + 2);
            if (end == std::string::npos)
                throw std::runtime_error("Unclosed source comment");
            end += 2;
            out.append(input, at, end - at);
            at = end;
            continue;
        }
        if (input[at] == '"' || input[at] == '\'') {
            char quote = input[at];
            size_t end = at + 1;
            while (end < input.size()) {
                if (input[end] == '\\') {
                    end += 2;
                    continue;
                }
                if (input[end++] == quote)
                    break;
            }
            out.append(input, at, end - at);
            at = end;
            continue;
        }
        if (input.compare(at, 5, "ctx->") != 0 || (at && ident(input[at - 1]))) {
            out += input[at++];
            continue;
        }
        size_t end = at + 5;
        while (end < input.size() && ident(input[end]))
            ++end;
        if (end < input.size() && input[end] == '[')
            end = balanced(input, end, '[', ']');
        if (end < input.size() && input[end] == '.')
            throw std::runtime_error(
                "Direct Context vector lane escape requires explicit source lowering");
        std::string expression = input.substr(at, end - at);
        size_t next = input.find_first_not_of(" \n\r\t", end),
               previous = out.find_last_not_of(" \n\r\t");
        // Only unary address-of may escape a field. A binary bitwise AND is
        // still a value read, including whitespace-separated expressions.
        size_t beforeAnd =
            previous == 0 ? std::string::npos : out.find_last_not_of(" \n\r\t", previous - 1);
        bool address = previous != std::string::npos && out[previous] == '&' &&
                       (beforeAnd == std::string::npos ||
                        std::string("(,=:{[;!?+-*/").find(out[beforeAnd]) != std::string::npos);
        bool write =
            next != std::string::npos &&
            ((input[next] == '=' && (next + 1 == input.size() || input[next + 1] != '=')) ||
             (next + 1 < input.size() && input[next + 1] == '=' &&
              std::string("+-*/|&^%").find(input[next]) != std::string::npos) ||
             input.compare(next, 2, "++") == 0 || input.compare(next, 2, "--") == 0 ||
             input.compare(next, 3, "<<=") == 0 || input.compare(next, 3, ">>=") == 0);
        if (previous != std::string::npos && previous > 0 &&
            (out.substr(previous - 1, 2) == "++" || out.substr(previous - 1, 2) == "--"))
            write = true;
        // Index expressions have their own source reads. Never read a CPU
        // register shadow merely to calculate the actual field address.
        const auto bracket = expression.find('[');
        if (bracket != std::string::npos)
            expression = expression.substr(0, bracket + 1) +
                         fields(expression.substr(bracket + 1, expression.size() - bracket - 2)) +
                         "]";
        if (address) {
            out.erase(previous, 1);
            out += "REO_SOURCE_ADDRESS(ctx," + expression + ")";
        } else if (write)
            out += "REO_SOURCE_WRITE(rdram,ctx," + expression + ")";
        else
            out += "REO_SOURCE_READ(ctx," + expression + ")";
        at = end;
    }
    return out;
}
inline std::string instrument(std::string text, bool generated = true) {
    if (generated) {
        // The emitted ABI has one actual Context pointer. Unknown aliases or
        // aggregate copies must be reviewed before compiling an owned route.
        if (std::regex_search(
                text,
                std::regex(R"((?:auto|R5900Context)\s*\*\s*(?!ctx\b)[A-Za-z_0-9]+\s*=\s*ctx\b)")) ||
            std::regex_search(text, std::regex(R"(=\s*\*\s*ctx\b)")) ||
            std::regex_search(text, std::regex(R"(\bctx\s+->)")))
            throw std::runtime_error(
                "Generated Context alias/clone syntax is outside reviewed source emitter");
    }
    text = maskedWrites(std::move(text));
    text = fields(text);
    const std::regex copy(R"((?:\bstd::|::)memcpy\s*\()");
    text = std::regex_replace(text, copy, "reo_source_instrumentation::copyBytes(");
    const std::regex move(R"((?:\bstd::|::)memmove\s*\()");
    text = std::regex_replace(text, move, "reo_source_instrumentation::moveBytes(");
    const std::regex fill(R"((?:\bstd::|::)memset\s*\()");
    text = std::regex_replace(text, fill, "reo_source_instrumentation::fillBytes(");
    const std::regex signature(
        R"((void\s+[A-Za-z_0-9]+\s*\(\s*uint8_t\s*\*\s*rdram\s*,\s*R5900Context\s*\*\s*ctx\s*,\s*PS2Runtime\s*\*\s*runtime\s*\)\s*\{))");
    text = std::regex_replace(
        text, signature,
        "$1\n    reo_source_instrumentation::EntryScope reo_source_entry(runtime,ctx);\n");
    if (generated) {
        const std::regex site(R"((//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)[^\n]*\n))");
        text = std::regex_replace(text, site, "$1    reo_source_entry.at(0x$2u,0x$3u);\n");
        const std::regex addr(R"(// Address:\s*0x([0-9a-fA-F]+))");
        std::smatch match;
        if (std::regex_search(text, match, addr)) {
            const std::string prefix =
                "    reo_source_instrumentation::EntryScope reo_source_entry(runtime,ctx);\n";
            const auto where = text.find(prefix);
            if (where != std::string::npos) {
                std::smatch first;
                std::regex raw(R"(//\s*0x[0-9a-fA-F]+:\s*0x([0-9a-fA-F]+))");
                const std::string opcode =
                    std::regex_search(text, first, raw) ? first[1].str() : "0";
                text.insert(
                    where + prefix.size(),
                    "    if(reo_source_instrumentation::dispatchEntry(rdram,*ctx,*runtime,0x" +
                        match[1].str() + "u))return;\n    reo_source_entry.at(0x" + match[1].str() +
                        "u,0x" + opcode + "u);\n");
            }
        }
    }
    // Native helper declarations in Common/Support must be parsed before
    // their local guarded macro overrides are installed.
    // Site-free stubs lack the generated Function comment. Bound the header
    // scan by the first actual generated function signature, so a debug block
    // inside its body can never move the accessor include into that body.
    std::smatch firstFunction;
    const size_t preambleEnd = std::regex_search(text, firstFunction, signature)
                                   ? size_t(firstFunction.position())
                                   : text.size();
    size_t includeEnd = 0;
    const auto functionHeading = text.find("// Function:");
    if (functionHeading != std::string::npos && functionHeading < preambleEnd)
        includeEnd = functionHeading;
    else {
        unsigned conditional = 0;
        for (size_t line = 0; line < preambleEnd;) {
            size_t end = text.find('\n', line);
            if (end == std::string::npos)
                end = text.size();
            const auto row = trim(text.substr(line, end - line));
            if (row.starts_with("#if"))
                ++conditional;
            else if (row.starts_with("#endif")) {
                if (conditional)
                    --conditional;
                if (!conditional)
                    includeEnd = end + 1;
            } else if (row.starts_with("#include") && !conditional)
                includeEnd = end + 1;
            else if (includeEnd && row.starts_with("namespace"))
                break;
            line = end + 1;
        }
    }
    text.insert(includeEnd, "#include \"source_instruction_access.hpp\"\n");
    return text;
}
} // namespace ps2recomp::source_guard

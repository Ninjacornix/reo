// Compile with REO_BASELINE_GUARD pointing to the unchanged source guard.
#define source_guard baseline_guard
#include REO_BASELINE_GUARD
#undef source_guard
#include "guard_generated_source.hpp"
#include <iostream>
#include <random>

std::string result(const std::string& text, bool generated, bool baseline) {
    try {
        return "OK:" + (baseline ? ps2recomp::baseline_guard::instrument(text, generated)
                                 : ps2recomp::source_guard::instrument(text, generated));
    } catch (const std::exception& error) {
        return std::string("REFUSED:") + error.what();
    }
}
int main() {
    const std::vector<std::string> fragments = {
        "ctx->pc=1;",
        "ctx->gpr[ctx->pc]+=2;",
        "x=ctx->pc & ctx->hi;",
        "&ctx->pc",
        "ctx->vu0_vf[2].x=1;",
        "++ctx->pc;",
        "ctx ->pc=0;",
        "xctx ->pc=0;",
        "auto *other=ctx;",
        "R5900Context *ctx2 = ctx;",
        "*other = *ctx;",
        "/* ctx->pc */",
        "// ctx->pc\n",
        "\"ctx->pc\"",
        "std::memcpy (p,q,4);",
        "::memmove(p,q,4);",
        "mystd::memset(p,0,4);",
        "ctx->vu0_vf[2] = _mm_blendv_ps(ctx->vu0_vf[2],x,y);",
        "// 0x100080: 0x01234567 synthetic\n",
        "// Address: 0x100080\n",
        "void synthetic(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime){\n}",
        "#include <one>\n#if ENABLED\n#include <two>\n#endif\n",
        "/*unterminated",
        "ctx->gpr[3",
        "//\n  0x100080: 0x00000000\n",
        "std::memcpy(p,q,4);std::memcpy(p,q,4);",
        "namespace synthetic {}\n"};
    std::mt19937 random(0x52454f);
    unsigned checked = 0;
    for (unsigned i = 0; i < 4000; ++i) {
        std::string text;
        for (unsigned n = 0, count = 1 + random() % 10; n < count; ++n)
            text += fragments[random() % fragments.size()] + (random() % 2 ? "\r\n" : " ");
        for (bool generated : {false, true}) {
            if (result(text, generated, true) != result(text, generated, false)) {
                std::cerr << "Guard differs in fixture " << i << " generated=" << generated << '\n';
                return 1;
            }
            ++checked;
        }
    }
    std::cout << "PASS exact output/refusal comparisons=" << checked << '\n';
}

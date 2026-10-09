#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E8758
// Address: 0x1e8758 - 0x1e8858
void sub_001E8758_0x1e8758(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E8758_0x1e8758");
#endif

    switch (ctx->pc) {
        case 0x1e8780u: goto label_1e8780;
        case 0x1e8794u: goto label_1e8794;
        case 0x1e87a4u: goto label_1e87a4;
        case 0x1e87b8u: goto label_1e87b8;
        case 0x1e87c8u: goto label_1e87c8;
        case 0x1e87dcu: goto label_1e87dc;
        case 0x1e87ecu: goto label_1e87ec;
        case 0x1e8800u: goto label_1e8800;
        case 0x1e8810u: goto label_1e8810;
        default: break;
    }

    ctx->pc = 0x1e8758u;

    // 0x1e8758: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x1e8758u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x1e875c: 0xffbe00c0  sd          $fp, 0xC0($sp)
    ctx->pc = 0x1e875cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 30));
    // 0x1e8760: 0xffbf00c8  sd          $ra, 0xC8($sp)
    ctx->pc = 0x1e8760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 200), GPR_U64(ctx, 31));
    // 0x1e8764: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8764u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8768: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8768u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e876c: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1e876cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e8770: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8770u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8774: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1e8774u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8778: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E8778u;
    SET_GPR_U32(ctx, 31, 0x1E8780u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8780u; }
        if (ctx->pc != 0x1E8780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8780u; }
        if (ctx->pc != 0x1E8780u) { return; }
    }
    ctx->pc = 0x1E8780u;
label_1e8780:
    // 0x1e8780: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1e8780u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e8784: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8784u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8788: 0x27858040  addiu       $a1, $gp, -0x7FC0
    ctx->pc = 0x1e8788u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934592));
    // 0x1e878c: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1E878Cu;
    SET_GPR_U32(ctx, 31, 0x1E8794u);
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8794u; }
        if (ctx->pc != 0x1E8794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8794u; }
        if (ctx->pc != 0x1E8794u) { return; }
    }
    ctx->pc = 0x1E8794u;
label_1e8794:
    // 0x1e8794: 0xafc20090  sw          $v0, 0x90($fp)
    ctx->pc = 0x1e8794u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 144), GPR_U32(ctx, 2));
    // 0x1e8798: 0x8fc40090  lw          $a0, 0x90($fp)
    ctx->pc = 0x1e8798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 144)));
    // 0x1e879c: 0xc040de0  jal         func_103780
    ctx->pc = 0x1E879Cu;
    SET_GPR_U32(ctx, 31, 0x1E87A4u);
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87A4u; }
        if (ctx->pc != 0x1E87A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87A4u; }
        if (ctx->pc != 0x1E87A4u) { return; }
    }
    ctx->pc = 0x1E87A4u;
label_1e87a4:
    // 0x1e87a4: 0xffc20098  sd          $v0, 0x98($fp)
    ctx->pc = 0x1e87a4u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 152), GPR_U64(ctx, 2));
    // 0x1e87a8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1e87a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e87ac: 0x27858040  addiu       $a1, $gp, -0x7FC0
    ctx->pc = 0x1e87acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934592));
    // 0x1e87b0: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1E87B0u;
    SET_GPR_U32(ctx, 31, 0x1E87B8u);
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87B8u; }
        if (ctx->pc != 0x1E87B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87B8u; }
        if (ctx->pc != 0x1E87B8u) { return; }
    }
    ctx->pc = 0x1E87B8u;
label_1e87b8:
    // 0x1e87b8: 0xafc20090  sw          $v0, 0x90($fp)
    ctx->pc = 0x1e87b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 144), GPR_U32(ctx, 2));
    // 0x1e87bc: 0x8fc40090  lw          $a0, 0x90($fp)
    ctx->pc = 0x1e87bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 144)));
    // 0x1e87c0: 0xc040de0  jal         func_103780
    ctx->pc = 0x1E87C0u;
    SET_GPR_U32(ctx, 31, 0x1E87C8u);
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87C8u; }
        if (ctx->pc != 0x1E87C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87C8u; }
        if (ctx->pc != 0x1E87C8u) { return; }
    }
    ctx->pc = 0x1E87C8u;
label_1e87c8:
    // 0x1e87c8: 0xffc200a0  sd          $v0, 0xA0($fp)
    ctx->pc = 0x1e87c8u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 160), GPR_U64(ctx, 2));
    // 0x1e87cc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1e87ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e87d0: 0x27858040  addiu       $a1, $gp, -0x7FC0
    ctx->pc = 0x1e87d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934592));
    // 0x1e87d4: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1E87D4u;
    SET_GPR_U32(ctx, 31, 0x1E87DCu);
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87DCu; }
        if (ctx->pc != 0x1E87DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87DCu; }
        if (ctx->pc != 0x1E87DCu) { return; }
    }
    ctx->pc = 0x1E87DCu;
label_1e87dc:
    // 0x1e87dc: 0xafc20090  sw          $v0, 0x90($fp)
    ctx->pc = 0x1e87dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 144), GPR_U32(ctx, 2));
    // 0x1e87e0: 0x8fc40090  lw          $a0, 0x90($fp)
    ctx->pc = 0x1e87e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 144)));
    // 0x1e87e4: 0xc040de0  jal         func_103780
    ctx->pc = 0x1E87E4u;
    SET_GPR_U32(ctx, 31, 0x1E87ECu);
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87ECu; }
        if (ctx->pc != 0x1E87ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E87ECu; }
        if (ctx->pc != 0x1E87ECu) { return; }
    }
    ctx->pc = 0x1E87ECu;
label_1e87ec:
    // 0x1e87ec: 0xffc200a8  sd          $v0, 0xA8($fp)
    ctx->pc = 0x1e87ecu;
    WRITE64(ADD32(GPR_U32(ctx, 30), 168), GPR_U64(ctx, 2));
    // 0x1e87f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1e87f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e87f4: 0x27858040  addiu       $a1, $gp, -0x7FC0
    ctx->pc = 0x1e87f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934592));
    // 0x1e87f8: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1E87F8u;
    SET_GPR_U32(ctx, 31, 0x1E8800u);
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8800u; }
        if (ctx->pc != 0x1E8800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8800u; }
        if (ctx->pc != 0x1E8800u) { return; }
    }
    ctx->pc = 0x1E8800u;
label_1e8800:
    // 0x1e8800: 0xafc20090  sw          $v0, 0x90($fp)
    ctx->pc = 0x1e8800u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 144), GPR_U32(ctx, 2));
    // 0x1e8804: 0x8fc40090  lw          $a0, 0x90($fp)
    ctx->pc = 0x1e8804u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 144)));
    // 0x1e8808: 0xc040de0  jal         func_103780
    ctx->pc = 0x1E8808u;
    SET_GPR_U32(ctx, 31, 0x1E8810u);
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8810u; }
        if (ctx->pc != 0x1E8810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8810u; }
        if (ctx->pc != 0x1E8810u) { return; }
    }
    ctx->pc = 0x1E8810u;
label_1e8810:
    // 0x1e8810: 0xffc200b0  sd          $v0, 0xB0($fp)
    ctx->pc = 0x1e8810u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 176), GPR_U64(ctx, 2));
    // 0x1e8814: 0xdfc200a0  ld          $v0, 0xA0($fp)
    ctx->pc = 0x1e8814u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 30), 160)));
    // 0x1e8818: 0x21a38  dsll        $v1, $v0, 8
    ctx->pc = 0x1e8818u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 8);
    // 0x1e881c: 0xdfc20098  ld          $v0, 0x98($fp)
    ctx->pc = 0x1e881cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 30), 152)));
    // 0x1e8820: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e8820u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e8824: 0xdfc200a8  ld          $v0, 0xA8($fp)
    ctx->pc = 0x1e8824u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 30), 168)));
    // 0x1e8828: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1e8828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1e882c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e882cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e8830: 0xdfc200b0  ld          $v0, 0xB0($fp)
    ctx->pc = 0x1e8830u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 30), 176)));
    // 0x1e8834: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x1e8834u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x1e8838: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e8838u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e883c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e883cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8840: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8840u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8844: 0xdfbe00c0  ld          $fp, 0xC0($sp)
    ctx->pc = 0x1e8844u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1e8848: 0xdfbf00c8  ld          $ra, 0xC8($sp)
    ctx->pc = 0x1e8848u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x1e884c: 0x27bd00d0  addiu       $sp, $sp, 0xD0
    ctx->pc = 0x1e884cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x1e8850: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8850u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E8780u: goto label_1e8780;
            case 0x1E8794u: goto label_1e8794;
            case 0x1E87A4u: goto label_1e87a4;
            case 0x1E87B8u: goto label_1e87b8;
            case 0x1E87C8u: goto label_1e87c8;
            case 0x1E87DCu: goto label_1e87dc;
            case 0x1E87ECu: goto label_1e87ec;
            case 0x1E8800u: goto label_1e8800;
            case 0x1E8810u: goto label_1e8810;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E8858u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

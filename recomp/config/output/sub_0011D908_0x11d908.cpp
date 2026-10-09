#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D908
// Address: 0x11d908 - 0x11d960
void sub_0011D908_0x11d908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D908_0x11d908");
#endif

    switch (ctx->pc) {
        case 0x11d918u: goto label_11d918;
        case 0x11d920u: goto label_11d920;
        case 0x11d928u: goto label_11d928;
        case 0x11d930u: goto label_11d930;
        case 0x11d938u: goto label_11d938;
        case 0x11d940u: goto label_11d940;
        case 0x11d948u: goto label_11d948;
        case 0x11d950u: goto label_11d950;
        default: break;
    }

    ctx->pc = 0x11d908u;

    // 0x11d908: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11d908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11d90c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11d90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11d910: 0xc0475b4  jal         func_11D6D0
    ctx->pc = 0x11D910u;
    SET_GPR_U32(ctx, 31, 0x11D918u);
    ctx->pc = 0x11D6D0u;
    if (runtime->hasFunction(0x11D6D0u)) {
        auto targetFn = runtime->lookupFunction(0x11D6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D918u; }
        if (ctx->pc != 0x11D918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6D0_0x11d6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D918u; }
        if (ctx->pc != 0x11D918u) { return; }
    }
    ctx->pc = 0x11D918u;
label_11d918:
    // 0x11d918: 0xc0475fe  jal         func_11D7F8
    ctx->pc = 0x11D918u;
    SET_GPR_U32(ctx, 31, 0x11D920u);
    ctx->pc = 0x11D7F8u;
    if (runtime->hasFunction(0x11D7F8u)) {
        auto targetFn = runtime->lookupFunction(0x11D7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D920u; }
        if (ctx->pc != 0x11D920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7F8_0x11d7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D920u; }
        if (ctx->pc != 0x11D920u) { return; }
    }
    ctx->pc = 0x11D920u;
label_11d920:
    // 0x11d920: 0xc04777a  jal         func_11DDE8
    ctx->pc = 0x11D920u;
    SET_GPR_U32(ctx, 31, 0x11D928u);
    ctx->pc = 0x11DDE8u;
    if (runtime->hasFunction(0x11DDE8u)) {
        auto targetFn = runtime->lookupFunction(0x11DDE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D928u; }
        if (ctx->pc != 0x11D928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DDE8_0x11dde8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D928u; }
        if (ctx->pc != 0x11D928u) { return; }
    }
    ctx->pc = 0x11D928u;
label_11d928:
    // 0x11d928: 0xc0477d8  jal         func_11DF60
    ctx->pc = 0x11D928u;
    SET_GPR_U32(ctx, 31, 0x11D930u);
    ctx->pc = 0x11D92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D928u;
            // 0x11d92c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF60u;
    if (runtime->hasFunction(0x11DF60u)) {
        auto targetFn = runtime->lookupFunction(0x11DF60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D930u; }
        if (ctx->pc != 0x11D930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF60_0x11df60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D930u; }
        if (ctx->pc != 0x11D930u) { return; }
    }
    ctx->pc = 0x11D930u;
label_11d930:
    // 0x11d930: 0xc047868  jal         func_11E1A0
    ctx->pc = 0x11D930u;
    SET_GPR_U32(ctx, 31, 0x11D938u);
    ctx->pc = 0x11E1A0u;
    if (runtime->hasFunction(0x11E1A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E1A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D938u; }
        if (ctx->pc != 0x11D938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E1A0_0x11e1a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D938u; }
        if (ctx->pc != 0x11D938u) { return; }
    }
    ctx->pc = 0x11D938u;
label_11d938:
    // 0x11d938: 0xc0454fe  jal         func_1153F8
    ctx->pc = 0x11D938u;
    SET_GPR_U32(ctx, 31, 0x11D940u);
    ctx->pc = 0x1153F8u;
    if (runtime->hasFunction(0x1153F8u)) {
        auto targetFn = runtime->lookupFunction(0x1153F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D940u; }
        if (ctx->pc != 0x11D940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001153F8_0x1153f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D940u; }
        if (ctx->pc != 0x11D940u) { return; }
    }
    ctx->pc = 0x11D940u;
label_11d940:
    // 0x11d940: 0xc04768c  jal         func_11DA30
    ctx->pc = 0x11D940u;
    SET_GPR_U32(ctx, 31, 0x11D948u);
    ctx->pc = 0x11DA30u;
    if (runtime->hasFunction(0x11DA30u)) {
        auto targetFn = runtime->lookupFunction(0x11DA30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D948u; }
        if (ctx->pc != 0x11D948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DA30_0x11da30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D948u; }
        if (ctx->pc != 0x11D948u) { return; }
    }
    ctx->pc = 0x11D948u;
label_11d948:
    // 0x11d948: 0xc0473c2  jal         func_11CF08
    ctx->pc = 0x11D948u;
    SET_GPR_U32(ctx, 31, 0x11D950u);
    ctx->pc = 0x11CF08u;
    if (runtime->hasFunction(0x11CF08u)) {
        auto targetFn = runtime->lookupFunction(0x11CF08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D950u; }
        if (ctx->pc != 0x11D950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CF08_0x11cf08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D950u; }
        if (ctx->pc != 0x11D950u) { return; }
    }
    ctx->pc = 0x11D950u;
label_11d950:
    // 0x11d950: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11d950u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d954: 0x8047d86  j           func_11F618
    ctx->pc = 0x11D954u;
    ctx->pc = 0x11D958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D954u;
            // 0x11d958: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F618u;
    if (runtime->hasFunction(0x11F618u)) {
        auto targetFn = runtime->lookupFunction(0x11F618u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011F618_0x11f618(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11D95Cu;
    // 0x11d95c: 0x0  nop
    ctx->pc = 0x11d95cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164900
// Address: 0x164900 - 0x1649c0
void sub_00164900_0x164900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164900_0x164900");
#endif

    switch (ctx->pc) {
        case 0x164968u: goto label_164968;
        case 0x164970u: goto label_164970;
        case 0x164984u: goto label_164984;
        case 0x1649a8u: goto label_1649a8;
        case 0x1649b0u: goto label_1649b0;
        default: break;
    }

    ctx->pc = 0x164900u;

    // 0x164900: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x164900u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x164904: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x164904u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x164908: 0x24a50750  addiu       $a1, $a1, 0x750
    ctx->pc = 0x164908u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1872));
    // 0x16490c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x16490cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x164910: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x164910u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x164914: 0x2406ffe0  addiu       $a2, $zero, -0x20
    ctx->pc = 0x164914u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967264));
    // 0x164918: 0x2442001f  addiu       $v0, $v0, 0x1F
    ctx->pc = 0x164918u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x16491c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x16491cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x164920: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x164920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x164924: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x164924u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x164928: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x164928u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x16492c: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x16492cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x164930: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x164930u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x164934: 0x2442001f  addiu       $v0, $v0, 0x1F
    ctx->pc = 0x164934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x164938: 0xaca3000c  sw          $v1, 0xC($a1)
    ctx->pc = 0x164938u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 3));
    // 0x16493c: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x16493cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x164940: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x164940u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x164944: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x164944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x164948: 0xaca30010  sw          $v1, 0x10($a1)
    ctx->pc = 0x164948u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 3));
    // 0x16494c: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x16494cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x164950: 0x3e00008  jr          $ra
    ctx->pc = 0x164950u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164950u;
            // 0x164954: 0xaca20014  sw          $v0, 0x14($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164968u: goto label_164968;
            case 0x164970u: goto label_164970;
            case 0x164984u: goto label_164984;
            case 0x1649A8u: goto label_1649a8;
            case 0x1649B0u: goto label_1649b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164958u;
    // 0x164958: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164958u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16495c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16495cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164960: 0xc04a87a  jal         func_12A1E8
    ctx->pc = 0x164960u;
    SET_GPR_U32(ctx, 31, 0x164968u);
    ctx->pc = 0x12A1E8u;
    if (runtime->hasFunction(0x12A1E8u)) {
        auto targetFn = runtime->lookupFunction(0x12A1E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164968u; }
        if (ctx->pc != 0x164968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1E8_0x12a1e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164968u; }
        if (ctx->pc != 0x164968u) { return; }
    }
    ctx->pc = 0x164968u;
label_164968:
    // 0x164968: 0xc04b246  jal         func_12C918
    ctx->pc = 0x164968u;
    SET_GPR_U32(ctx, 31, 0x164970u);
    ctx->pc = 0x12C918u;
    if (runtime->hasFunction(0x12C918u)) {
        auto targetFn = runtime->lookupFunction(0x12C918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164970u; }
        if (ctx->pc != 0x164970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C918_0x12c918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164970u; }
        if (ctx->pc != 0x164970u) { return; }
    }
    ctx->pc = 0x164970u;
label_164970:
    // 0x164970: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x164970u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x164974: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x164974u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164978: 0x24840750  addiu       $a0, $a0, 0x750
    ctx->pc = 0x164978u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1872));
    // 0x16497c: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x16497Cu;
    SET_GPR_U32(ctx, 31, 0x164984u);
    ctx->pc = 0x164980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16497Cu;
            // 0x164980: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164984u; }
        if (ctx->pc != 0x164984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164984u; }
        if (ctx->pc != 0x164984u) { return; }
    }
    ctx->pc = 0x164984u;
label_164984:
    // 0x164984: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x164984u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164988: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164988u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16498c: 0x3e00008  jr          $ra
    ctx->pc = 0x16498Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16498Cu;
            // 0x164990: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164968u: goto label_164968;
            case 0x164970u: goto label_164970;
            case 0x164984u: goto label_164984;
            case 0x1649A8u: goto label_1649a8;
            case 0x1649B0u: goto label_1649b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164994u;
    // 0x164994: 0x0  nop
    ctx->pc = 0x164994u;
    // NOP
    // 0x164998: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16499c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16499cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1649a0: 0xc04b24c  jal         func_12C930
    ctx->pc = 0x1649A0u;
    SET_GPR_U32(ctx, 31, 0x1649A8u);
    ctx->pc = 0x12C930u;
    if (runtime->hasFunction(0x12C930u)) {
        auto targetFn = runtime->lookupFunction(0x12C930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649A8u; }
        if (ctx->pc != 0x1649A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C930_0x12c930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649A8u; }
        if (ctx->pc != 0x1649A8u) { return; }
    }
    ctx->pc = 0x1649A8u;
label_1649a8:
    // 0x1649a8: 0xc04a8e2  jal         func_12A388
    ctx->pc = 0x1649A8u;
    SET_GPR_U32(ctx, 31, 0x1649B0u);
    ctx->pc = 0x12A388u;
    if (runtime->hasFunction(0x12A388u)) {
        auto targetFn = runtime->lookupFunction(0x12A388u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649B0u; }
        if (ctx->pc != 0x1649B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A388_0x12a388(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649B0u; }
        if (ctx->pc != 0x1649B0u) { return; }
    }
    ctx->pc = 0x1649B0u;
label_1649b0:
    // 0x1649b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1649b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1649b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1649b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1649b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1649B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1649BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1649B8u;
            // 0x1649bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164968u: goto label_164968;
            case 0x164970u: goto label_164970;
            case 0x164984u: goto label_164984;
            case 0x1649A8u: goto label_1649a8;
            case 0x1649B0u: goto label_1649b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1649C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9130
// Address: 0x1d9130 - 0x1d91a0
void sub_001D9130_0x1d9130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9130_0x1d9130");
#endif

    switch (ctx->pc) {
        case 0x1d9144u: goto label_1d9144;
        case 0x1d915cu: goto label_1d915c;
        case 0x1d9180u: goto label_1d9180;
        case 0x1d918cu: goto label_1d918c;
        default: break;
    }

    ctx->pc = 0x1d9130u;

    // 0x1d9130: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d9130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d9134: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d9134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d9138: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d9138u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d913c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D913Cu;
    SET_GPR_U32(ctx, 31, 0x1D9144u);
    ctx->pc = 0x1D9140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D913Cu;
            // 0x1d9140: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9144u; }
        if (ctx->pc != 0x1D9144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9144u; }
        if (ctx->pc != 0x1D9144u) { return; }
    }
    ctx->pc = 0x1D9144u;
label_1d9144:
    // 0x1d9144: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d9144u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9148: 0x24060200  addiu       $a2, $zero, 0x200
    ctx->pc = 0x1d9148u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1d914c: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1d914cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1d9150: 0x2610729c  addiu       $s0, $s0, 0x729C
    ctx->pc = 0x1d9150u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 29340));
    // 0x1d9154: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1D9154u;
    SET_GPR_U32(ctx, 31, 0x1D915Cu);
    ctx->pc = 0x1D9158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9154u;
            // 0x1d9158: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D915Cu; }
        if (ctx->pc != 0x1D915Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D915Cu; }
        if (ctx->pc != 0x1D915Cu) { return; }
    }
    ctx->pc = 0x1D915Cu;
label_1d915c:
    // 0x1d915c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d915cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d9160: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d9160u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d9164: 0x2404003a  addiu       $a0, $zero, 0x3A
    ctx->pc = 0x1d9164u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 58));
    // 0x1d9168: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d9168u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d916c: 0x24060220  addiu       $a2, $zero, 0x220
    ctx->pc = 0x1d916cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 544));
    // 0x1d9170: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d9170u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d9174: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d9174u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d9178: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D9178u;
    SET_GPR_U32(ctx, 31, 0x1D9180u);
    ctx->pc = 0x1D917Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9178u;
            // 0x1d917c: 0xa20001ff  sb          $zero, 0x1FF($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 511), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9180u; }
        if (ctx->pc != 0x1D9180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9180u; }
        if (ctx->pc != 0x1D9180u) { return; }
    }
    ctx->pc = 0x1D9180u;
label_1d9180:
    // 0x1d9180: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d9180u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d9184: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D9184u;
    SET_GPR_U32(ctx, 31, 0x1D918Cu);
    ctx->pc = 0x1D9188u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9184u;
            // 0x1d9188: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D918Cu; }
        if (ctx->pc != 0x1D918Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D918Cu; }
        if (ctx->pc != 0x1D918Cu) { return; }
    }
    ctx->pc = 0x1D918Cu;
label_1d918c:
    // 0x1d918c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d918cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9190: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d9190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9194: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9194u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9198: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D919Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9198u;
            // 0x1d919c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9144u: goto label_1d9144;
            case 0x1D915Cu: goto label_1d915c;
            case 0x1D9180u: goto label_1d9180;
            case 0x1D918Cu: goto label_1d918c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D91A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7E90
// Address: 0x1d7e90 - 0x1d7f60
void sub_001D7E90_0x1d7e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7E90_0x1d7e90");
#endif

    switch (ctx->pc) {
        case 0x1d7eb4u: goto label_1d7eb4;
        case 0x1d7f04u: goto label_1d7f04;
        case 0x1d7f2cu: goto label_1d7f2c;
        case 0x1d7f38u: goto label_1d7f38;
        default: break;
    }

    ctx->pc = 0x1d7e90u;

    // 0x1d7e90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d7e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d7e94: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d7e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d7e98: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d7e98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d7e9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d7e9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d7ea0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d7ea0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7ea4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7ea4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7ea8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d7ea8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7eac: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7EACu;
    SET_GPR_U32(ctx, 31, 0x1D7EB4u);
    ctx->pc = 0x1D7EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7EACu;
            // 0x1d7eb0: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7EB4u; }
        if (ctx->pc != 0x1D7EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7EB4u; }
        if (ctx->pc != 0x1D7EB4u) { return; }
    }
    ctx->pc = 0x1D7EB4u;
label_1d7eb4:
    // 0x1d7eb4: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x1d7eb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d7eb8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7eb8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7ebc: 0x1c400004  bgtz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D7EBCu;
    {
        const bool branch_taken_0x1d7ebc = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d7ebc) {
            ctx->pc = 0x1D7ED0u;
            goto label_1d7ed0;
        }
    }
    ctx->pc = 0x1D7EC4u;
    // 0x1d7ec4: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1D7EC4u;
    {
        const bool branch_taken_0x1d7ec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7EC4u;
            // 0x1d7ec8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7ec4) {
            ctx->pc = 0x1D7F40u;
            goto label_1d7f40;
        }
    }
    ctx->pc = 0x1D7ECCu;
    // 0x1d7ecc: 0x0  nop
    ctx->pc = 0x1d7eccu;
    // NOP
label_1d7ed0:
    // 0x1d7ed0: 0x28410c01  slti        $at, $v0, 0xC01
    ctx->pc = 0x1d7ed0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3073) ? 1 : 0);
    // 0x1d7ed4: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D7ED4u;
    {
        const bool branch_taken_0x1d7ed4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d7ed4) {
            ctx->pc = 0x1D7EE0u;
            goto label_1d7ee0;
        }
    }
    ctx->pc = 0x1D7EDCu;
    // 0x1d7edc: 0x24100c00  addiu       $s0, $zero, 0xC00
    ctx->pc = 0x1d7edcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3072));
label_1d7ee0:
    // 0x1d7ee0: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d7ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d7ee4: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d7ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d7ee8: 0x10343c  dsll32      $a2, $s0, 16
    ctx->pc = 0x1d7ee8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d7eec: 0xa4520000  sh          $s2, 0x0($v0)
    ctx->pc = 0x1d7eecu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1d7ef0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d7ef0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7ef4: 0x6343f  dsra32      $a2, $a2, 16
    ctx->pc = 0x1d7ef4u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x1d7ef8: 0x24440004  addiu       $a0, $v0, 0x4
    ctx->pc = 0x1d7ef8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1d7efc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D7EFCu;
    SET_GPR_U32(ctx, 31, 0x1D7F04u);
    ctx->pc = 0x1D7F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7EFCu;
            // 0x1d7f00: 0xa4500002  sh          $s0, 0x2($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F04u; }
        if (ctx->pc != 0x1D7F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F04u; }
        if (ctx->pc != 0x1D7F04u) { return; }
    }
    ctx->pc = 0x1D7F04u;
label_1d7f04:
    // 0x1d7f04: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x1d7f04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d7f08: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7f08u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7f0c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7f0cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7f10: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7f10u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7f14: 0x24460026  addiu       $a2, $v0, 0x26
    ctx->pc = 0x1d7f14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 38));
    // 0x1d7f18: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1d7f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d7f1c: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7f1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7f20: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7f20u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7f24: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7F24u;
    SET_GPR_U32(ctx, 31, 0x1D7F2Cu);
    ctx->pc = 0x1D7F28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7F24u;
            // 0x1d7f28: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F2Cu; }
        if (ctx->pc != 0x1D7F2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F2Cu; }
        if (ctx->pc != 0x1D7F2Cu) { return; }
    }
    ctx->pc = 0x1D7F2Cu;
label_1d7f2c:
    // 0x1d7f2c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7f2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7f30: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D7F30u;
    SET_GPR_U32(ctx, 31, 0x1D7F38u);
    ctx->pc = 0x1D7F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7F30u;
            // 0x1d7f34: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F38u; }
        if (ctx->pc != 0x1D7F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7F38u; }
        if (ctx->pc != 0x1D7F38u) { return; }
    }
    ctx->pc = 0x1D7F38u;
label_1d7f38:
    // 0x1d7f38: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d7f38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7f3c: 0x0  nop
    ctx->pc = 0x1d7f3cu;
    // NOP
label_1d7f40:
    // 0x1d7f40: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d7f40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d7f44: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d7f44u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d7f48: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d7f48u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7f4c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7f4cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7f50: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7F50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7F50u;
            // 0x1d7f54: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7EB4u: goto label_1d7eb4;
            case 0x1D7ED0u: goto label_1d7ed0;
            case 0x1D7EE0u: goto label_1d7ee0;
            case 0x1D7F04u: goto label_1d7f04;
            case 0x1D7F2Cu: goto label_1d7f2c;
            case 0x1D7F38u: goto label_1d7f38;
            case 0x1D7F40u: goto label_1d7f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7F58u;
    // 0x1d7f58: 0x0  nop
    ctx->pc = 0x1d7f58u;
    // NOP
    // 0x1d7f5c: 0x0  nop
    ctx->pc = 0x1d7f5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

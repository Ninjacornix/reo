#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193E20
// Address: 0x193e20 - 0x193ed0
void sub_00193E20_0x193e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193E20_0x193e20");
#endif

    switch (ctx->pc) {
        case 0x193e50u: goto label_193e50;
        case 0x193e8cu: goto label_193e8c;
        case 0x193eb0u: goto label_193eb0;
        default: break;
    }

    ctx->pc = 0x193e20u;

    // 0x193e20: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x193e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x193e24: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x193e24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x193e28: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x193e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x193e2c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x193e2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x193e30: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x193e30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x193e34: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x193e34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x193e38: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x193e38u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e3c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x193e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x193e40: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x193e40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x193e44: 0x24520001  addiu       $s2, $v0, 0x1
    ctx->pc = 0x193e44u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x193e48: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x193E48u;
    SET_GPR_U32(ctx, 31, 0x193E50u);
    ctx->pc = 0x193E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193E48u;
            // 0x193e4c: 0x122100  sll         $a0, $s2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193E50u; }
        if (ctx->pc != 0x193E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193E50u; }
        if (ctx->pc != 0x193E50u) { return; }
    }
    ctx->pc = 0x193E50u;
label_193e50:
    // 0x193e50: 0x8e290000  lw          $t1, 0x0($s1)
    ctx->pc = 0x193e50u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x193e54: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x193e54u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e58: 0x2643ffff  addiu       $v1, $s2, -0x1
    ctx->pc = 0x193e58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x193e5c: 0x3c025100  lui         $v0, 0x5100
    ctx->pc = 0x193e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20736 << 16));
    // 0x193e60: 0x3c088000  lui         $t0, 0x8000
    ctx->pc = 0x193e60u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32768 << 16));
    // 0x193e64: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x193e64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x193e68: 0x3c071300  lui         $a3, 0x1300
    ctx->pc = 0x193e68u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4864 << 16));
    // 0x193e6c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x193e6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e70: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e74: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x193e74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e78: 0x1281825  or          $v1, $t1, $t0
    ctx->pc = 0x193e78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x193e7c: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x193e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x193e80: 0xae270008  sw          $a3, 0x8($s1)
    ctx->pc = 0x193e80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 7));
    // 0x193e84: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x193E84u;
    SET_GPR_U32(ctx, 31, 0x193E8Cu);
    ctx->pc = 0x193E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193E84u;
            // 0x193e88: 0xae22000c  sw          $v0, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193E8Cu; }
        if (ctx->pc != 0x193E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193E8Cu; }
        if (ctx->pc != 0x193E8Cu) { return; }
    }
    ctx->pc = 0x193E8Cu;
label_193e8c:
    // 0x193e8c: 0x10193c  dsll32      $v1, $s0, 4
    ctx->pc = 0x193e8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 4));
    // 0x193e90: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x193e90u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x193e94: 0x3193e  dsrl32      $v1, $v1, 4
    ctx->pc = 0x193e94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 4));
    // 0x193e98: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x193e98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x193e9c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x193e9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193ea0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x193ea0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193ea4: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x193ea4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x193ea8: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x193EA8u;
    SET_GPR_U32(ctx, 31, 0x193EB0u);
    ctx->pc = 0x193EACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193EA8u;
            // 0x193eac: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193EB0u; }
        if (ctx->pc != 0x193EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193EB0u; }
        if (ctx->pc != 0x193EB0u) { return; }
    }
    ctx->pc = 0x193EB0u;
label_193eb0:
    // 0x193eb0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x193eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193eb4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193eb8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x193eb8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193ebc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x193ebcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193ec0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x193ec0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x193ec4: 0x3e00008  jr          $ra
    ctx->pc = 0x193EC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193EC4u;
            // 0x193ec8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193E50u: goto label_193e50;
            case 0x193E8Cu: goto label_193e8c;
            case 0x193EB0u: goto label_193eb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193ECCu;
    // 0x193ecc: 0x0  nop
    ctx->pc = 0x193eccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

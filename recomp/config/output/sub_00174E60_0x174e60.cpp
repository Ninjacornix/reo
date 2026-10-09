#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174E60
// Address: 0x174e60 - 0x174f58
void sub_00174E60_0x174e60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174E60_0x174e60");
#endif

    switch (ctx->pc) {
        case 0x174e80u: goto label_174e80;
        case 0x174ebcu: goto label_174ebc;
        case 0x174ed4u: goto label_174ed4;
        case 0x174ef0u: goto label_174ef0;
        case 0x174f08u: goto label_174f08;
        default: break;
    }

    ctx->pc = 0x174e60u;

    // 0x174e60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174e60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174e64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174e68: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x174e68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174e6c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x174e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x174e70: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x174e70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174e74: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x174e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x174e78: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174E78u;
    SET_GPR_U32(ctx, 31, 0x174E80u);
    ctx->pc = 0x174E7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174E78u;
            // 0x174e7c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174E80u; }
        if (ctx->pc != 0x174E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174E80u; }
        if (ctx->pc != 0x174E80u) { return; }
    }
    ctx->pc = 0x174E80u;
label_174e80:
    // 0x174e80: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174e80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174e84: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x174E84u;
    {
        const bool branch_taken_0x174e84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174E84u;
            // 0x174e88: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174e84) {
            ctx->pc = 0x174EA8u;
            goto label_174ea8;
        }
    }
    ctx->pc = 0x174E8Cu;
    // 0x174e8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174e8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174e90: 0x34a50158  ori         $a1, $a1, 0x158
    ctx->pc = 0x174e90u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)344);
    // 0x174e94: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174e94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174e98: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x174e98u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174e9c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x174e9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174ea0: 0x805a704  j           func_169C10
    ctx->pc = 0x174EA0u;
    ctx->pc = 0x174EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174EA0u;
            // 0x174ea4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174EA8u;
label_174ea8:
    // 0x174ea8: 0x8e112ab0  lw          $s1, 0x2AB0($s0)
    ctx->pc = 0x174ea8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x174eac: 0x52200025  beql        $s1, $zero, . + 4 + (0x25 << 2)
    ctx->pc = 0x174EACu;
    {
        const bool branch_taken_0x174eac = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x174eac) {
            ctx->pc = 0x174EB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174EACu;
            // 0x174eb0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174F44u;
            goto label_174f44;
        }
    }
    ctx->pc = 0x174EB4u;
    // 0x174eb4: 0xc05cee0  jal         func_173B80
    ctx->pc = 0x174EB4u;
    SET_GPR_U32(ctx, 31, 0x174EBCu);
    ctx->pc = 0x174EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174EB4u;
            // 0x174eb8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173B80u;
    if (runtime->hasFunction(0x173B80u)) {
        auto targetFn = runtime->lookupFunction(0x173B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174EBCu; }
        if (ctx->pc != 0x174EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B80_0x173b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174EBCu; }
        if (ctx->pc != 0x174EBCu) { return; }
    }
    ctx->pc = 0x174EBCu;
label_174ebc:
    // 0x174ebc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x174ebcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ec0: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x174ec0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x174ec4: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x174EC4u;
    {
        const bool branch_taken_0x174ec4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x174EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174EC4u;
            // 0x174ec8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174ec4) {
            ctx->pc = 0x174F40u;
            goto label_174f40;
        }
    }
    ctx->pc = 0x174ECCu;
    // 0x174ecc: 0xc05d518  jal         func_175460
    ctx->pc = 0x174ECCu;
    SET_GPR_U32(ctx, 31, 0x174ED4u);
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174ED4u; }
        if (ctx->pc != 0x174ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174ED4u; }
        if (ctx->pc != 0x174ED4u) { return; }
    }
    ctx->pc = 0x174ED4u;
label_174ed4:
    // 0x174ed4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x174ed4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ed8: 0x8e220da4  lw          $v0, 0xDA4($s1)
    ctx->pc = 0x174ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 3492)));
    // 0x174edc: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x174edcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x174ee0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x174EE0u;
    {
        const bool branch_taken_0x174ee0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x174EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174EE0u;
            // 0x174ee4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174ee0) {
            ctx->pc = 0x174EF0u;
            goto label_174ef0;
        }
    }
    ctx->pc = 0x174EE8u;
    // 0x174ee8: 0xc05d518  jal         func_175460
    ctx->pc = 0x174EE8u;
    SET_GPR_U32(ctx, 31, 0x174EF0u);
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174EF0u; }
        if (ctx->pc != 0x174EF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174EF0u; }
        if (ctx->pc != 0x174EF0u) { return; }
    }
    ctx->pc = 0x174EF0u;
label_174ef0:
    // 0x174ef0: 0x8e220da8  lw          $v0, 0xDA8($s1)
    ctx->pc = 0x174ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 3496)));
    // 0x174ef4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x174EF4u;
    {
        const bool branch_taken_0x174ef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x174EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174EF4u;
            // 0x174ef8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174ef4) {
            ctx->pc = 0x174F08u;
            goto label_174f08;
        }
    }
    ctx->pc = 0x174EFCu;
    // 0x174efc: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x174efcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x174f00: 0xc05d518  jal         func_175460
    ctx->pc = 0x174F00u;
    SET_GPR_U32(ctx, 31, 0x174F08u);
    ctx->pc = 0x174F04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174F00u;
            // 0x174f04: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174F08u; }
        if (ctx->pc != 0x174F08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174F08u; }
        if (ctx->pc != 0x174F08u) { return; }
    }
    ctx->pc = 0x174F08u;
label_174f08:
    // 0x174f08: 0x6a420007  ldl         $v0, 0x7($s2)
    ctx->pc = 0x174f08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x174f0c: 0x6e420000  ldr         $v0, 0x0($s2)
    ctx->pc = 0x174f0cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x174f10: 0x8e430008  lw          $v1, 0x8($s2)
    ctx->pc = 0x174f10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x174f14: 0xb2022abb  sdl         $v0, 0x2ABB($s0)
    ctx->pc = 0x174f14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 10939); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x174f18: 0xb6022ab4  sdr         $v0, 0x2AB4($s0)
    ctx->pc = 0x174f18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 10932); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x174f1c: 0xae032abc  sw          $v1, 0x2ABC($s0)
    ctx->pc = 0x174f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 10940), GPR_U32(ctx, 3));
    // 0x174f20: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x174f20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174f24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174f24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174f28: 0x2405000d  addiu       $a1, $zero, 0xD
    ctx->pc = 0x174f28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x174f2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174f2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174f30: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x174f30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174f34: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x174f34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174f38: 0x805ded2  j           func_177B48
    ctx->pc = 0x174F38u;
    ctx->pc = 0x174F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174F38u;
            // 0x174f3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B48u;
    if (runtime->hasFunction(0x177B48u)) {
        auto targetFn = runtime->lookupFunction(0x177B48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177B48_0x177b48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174F40u;
label_174f40:
    // 0x174f40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174f40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_174f44:
    // 0x174f44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174f44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174f48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x174f48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174f4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x174f4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174f50: 0x3e00008  jr          $ra
    ctx->pc = 0x174F50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174F50u;
            // 0x174f54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174E80u: goto label_174e80;
            case 0x174EA8u: goto label_174ea8;
            case 0x174EBCu: goto label_174ebc;
            case 0x174ED4u: goto label_174ed4;
            case 0x174EF0u: goto label_174ef0;
            case 0x174F08u: goto label_174f08;
            case 0x174F40u: goto label_174f40;
            case 0x174F44u: goto label_174f44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174F58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

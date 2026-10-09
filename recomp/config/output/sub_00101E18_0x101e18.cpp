#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101E18
// Address: 0x101e18 - 0x101f60
void sub_00101E18_0x101e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101E18_0x101e18");
#endif

    switch (ctx->pc) {
        case 0x101e44u: goto label_101e44;
        case 0x101ea4u: goto label_101ea4;
        case 0x101ec4u: goto label_101ec4;
        case 0x101eccu: goto label_101ecc;
        default: break;
    }

    ctx->pc = 0x101e18u;

    // 0x101e18: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101e18u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101e1c: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x101e1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    // 0x101e20: 0x48c2e000  ctc2.ni     $v0, $vi28
    ctx->pc = 0x101e20u;
    ctx->vu0_itop = GPR_U32(ctx, 2) & 0x3FF;
    // 0x101e24: 0x3e00008  jr          $ra
    ctx->pc = 0x101E24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101E2Cu;
    // 0x101e2c: 0x0  nop
    ctx->pc = 0x101e2cu;
    // NOP
    // 0x101e30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x101e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x101e34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x101e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x101e38: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x101e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x101e3c: 0xc0407d8  jal         func_101F60
    ctx->pc = 0x101E3Cu;
    SET_GPR_U32(ctx, 31, 0x101E44u);
    ctx->pc = 0x101E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101E3Cu;
            // 0x101e40: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101F60u;
    if (runtime->hasFunction(0x101F60u)) {
        auto targetFn = runtime->lookupFunction(0x101F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101E44u; }
        if (ctx->pc != 0x101E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101F60_0x101f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101E44u; }
        if (ctx->pc != 0x101E44u) { return; }
    }
    ctx->pc = 0x101E44u;
label_101e44:
    // 0x101e44: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x101e44u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101e48: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x101e48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x101e4c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x101E4Cu;
    {
        const bool branch_taken_0x101e4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101E4Cu;
            // 0x101e50: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101e4c) {
            ctx->pc = 0x101E7Cu;
            goto label_101e7c;
        }
    }
    ctx->pc = 0x101E54u;
    // 0x101e54: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x101e54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x101e58: 0x244276c0  addiu       $v0, $v0, 0x76C0
    ctx->pc = 0x101e58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30400));
    // 0x101e5c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x101e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x101e60: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x101e60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x101e64: 0x800008  jr          $a0
    ctx->pc = 0x101E64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101E6Cu;
label_101e6c:
    // 0x101e6c: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101e6cu;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101e70: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x101e70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x101e74: 0x48c2e000  ctc2.ni     $v0, $vi28
    ctx->pc = 0x101e74u;
    ctx->vu0_itop = GPR_U32(ctx, 2) & 0x3FF;
label_101e78:
    // 0x101e78: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x101e78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_101e7c:
    // 0x101e7c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101e7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101e80: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x101e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101e84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x101e84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x101e88: 0x3e00008  jr          $ra
    ctx->pc = 0x101E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101E88u;
            // 0x101e8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101E90u;
    // 0x101e90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x101e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x101e94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x101e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x101e98: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x101e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x101e9c: 0xc0407d8  jal         func_101F60
    ctx->pc = 0x101E9Cu;
    SET_GPR_U32(ctx, 31, 0x101EA4u);
    ctx->pc = 0x101EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101E9Cu;
            // 0x101ea0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101F60u;
    if (runtime->hasFunction(0x101F60u)) {
        auto targetFn = runtime->lookupFunction(0x101F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EA4u; }
        if (ctx->pc != 0x101EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101F60_0x101f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EA4u; }
        if (ctx->pc != 0x101EA4u) { return; }
    }
    ctx->pc = 0x101EA4u;
label_101ea4:
    // 0x101ea4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x101ea4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101ea8: 0x28620004  slti        $v0, $v1, 0x4
    ctx->pc = 0x101ea8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x101eac: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x101EACu;
    {
        const bool branch_taken_0x101eac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101EACu;
            // 0x101eb0: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101eac) {
            ctx->pc = 0x101ED0u;
            goto label_101ed0;
        }
    }
    ctx->pc = 0x101EB4u;
    // 0x101eb4: 0x18600007  blez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x101EB4u;
    {
        const bool branch_taken_0x101eb4 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x101EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101EB4u;
            // 0x101eb8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101eb4) {
            ctx->pc = 0x101ED4u;
            goto label_101ed4;
        }
    }
    ctx->pc = 0x101EBCu;
    // 0x101ebc: 0xc0407ec  jal         func_101FB0
    ctx->pc = 0x101EBCu;
    SET_GPR_U32(ctx, 31, 0x101EC4u);
    ctx->pc = 0x101EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101EBCu;
            // 0x101ec0: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101FB0u;
    if (runtime->hasFunction(0x101FB0u)) {
        auto targetFn = runtime->lookupFunction(0x101FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EC4u; }
        if (ctx->pc != 0x101EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101FB0_0x101fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EC4u; }
        if (ctx->pc != 0x101EC4u) { return; }
    }
    ctx->pc = 0x101EC4u;
label_101ec4:
    // 0x101ec4: 0xc0407e8  jal         func_101FA0
    ctx->pc = 0x101EC4u;
    SET_GPR_U32(ctx, 31, 0x101ECCu);
    ctx->pc = 0x101EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101EC4u;
            // 0x101ec8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101FA0u;
    if (runtime->hasFunction(0x101FA0u)) {
        auto targetFn = runtime->lookupFunction(0x101FA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ECCu; }
        if (ctx->pc != 0x101ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101FA0_0x101fa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ECCu; }
        if (ctx->pc != 0x101ECCu) { return; }
    }
    ctx->pc = 0x101ECCu;
label_101ecc:
    // 0x101ecc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101eccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101ed0:
    // 0x101ed0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x101ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_101ed4:
    // 0x101ed4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x101ed4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x101ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x101ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101ED8u;
            // 0x101edc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101EE0u;
    // 0x101ee0: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x101ee0u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x101ee4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x101ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101ee8: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101EE8u;
    {
        const bool branch_taken_0x101ee8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x101ee8) {
            ctx->pc = 0x101EF8u;
            goto label_101ef8;
        }
    }
    ctx->pc = 0x101EF0u;
    // 0x101ef0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x101EF0u;
    {
        const bool branch_taken_0x101ef0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101EF0u;
            // 0x101ef4: 0x34630004  ori         $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101ef0) {
            ctx->pc = 0x101F04u;
            goto label_101f04;
        }
    }
    ctx->pc = 0x101EF8u;
label_101ef8:
    // 0x101ef8: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x101ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x101efc: 0x3442fffb  ori         $v0, $v0, 0xFFFB
    ctx->pc = 0x101efcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65531);
    // 0x101f00: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x101f00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_101f04:
    // 0x101f04: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x101f04u;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x101f08: 0x3e00008  jr          $ra
    ctx->pc = 0x101F08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F10u;
    // 0x101f10: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x101f10u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x101f14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x101f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101f18: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101F18u;
    {
        const bool branch_taken_0x101f18 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x101f18) {
            ctx->pc = 0x101F28u;
            goto label_101f28;
        }
    }
    ctx->pc = 0x101F20u;
    // 0x101f20: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x101F20u;
    {
        const bool branch_taken_0x101f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F20u;
            // 0x101f24: 0x34630008  ori         $v1, $v1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101f20) {
            ctx->pc = 0x101F34u;
            goto label_101f34;
        }
    }
    ctx->pc = 0x101F28u;
label_101f28:
    // 0x101f28: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x101f28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x101f2c: 0x3442fff7  ori         $v0, $v0, 0xFFF7
    ctx->pc = 0x101f2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65527);
    // 0x101f30: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x101f30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_101f34:
    // 0x101f34: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x101f34u;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x101f38: 0x3e00008  jr          $ra
    ctx->pc = 0x101F38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F40u;
    // 0x101f40: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101f40u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101f44: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x101f44u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x101f48: 0x3e00008  jr          $ra
    ctx->pc = 0x101F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F48u;
            // 0x101f4c: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F50u;
    // 0x101f50: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101f50u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101f54: 0x210c2  srl         $v0, $v0, 3
    ctx->pc = 0x101f54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 3));
    // 0x101f58: 0x3e00008  jr          $ra
    ctx->pc = 0x101F58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F58u;
            // 0x101f5c: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

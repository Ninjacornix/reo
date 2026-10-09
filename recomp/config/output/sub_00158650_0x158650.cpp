#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158650
// Address: 0x158650 - 0x158750
void sub_00158650_0x158650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158650_0x158650");
#endif

    switch (ctx->pc) {
        case 0x158690u: goto label_158690;
        case 0x158700u: goto label_158700;
        default: break;
    }

    ctx->pc = 0x158650u;

    // 0x158650: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x158650u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x158654: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x158654u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158658: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15865c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15865cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158660: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158664: 0x2058823  subu        $s1, $s0, $a1
    ctx->pc = 0x158664u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x158668: 0x230102b  sltu        $v0, $s1, $s0
    ctx->pc = 0x158668u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x15866c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15866cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x158670: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x158670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x158674: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x158674u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158678: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x158678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15867c: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x15867Cu;
    {
        const bool branch_taken_0x15867c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15867Cu;
            // 0x158680: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15867c) {
            ctx->pc = 0x15872Cu;
            goto label_15872c;
        }
    }
    ctx->pc = 0x158684u;
    // 0x158684: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x158684u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x158688: 0x24140003  addiu       $s4, $zero, 0x3
    ctx->pc = 0x158688u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15868c: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x15868cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_158690:
    // 0x158690: 0x1072000b  beq         $v1, $s2, . + 4 + (0xB << 2)
    ctx->pc = 0x158690u;
    {
        const bool branch_taken_0x158690 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 18));
        ctx->pc = 0x158694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158690u;
            // 0x158694: 0x82020000  lb          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158690) {
            ctx->pc = 0x1586C0u;
            goto label_1586c0;
        }
    }
    ctx->pc = 0x158698u;
    // 0x158698: 0x50600021  beql        $v1, $zero, . + 4 + (0x21 << 2)
    ctx->pc = 0x158698u;
    {
        const bool branch_taken_0x158698 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x158698) {
            ctx->pc = 0x15869Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158698u;
            // 0x15869c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158720u;
            goto label_158720;
        }
    }
    ctx->pc = 0x1586A0u;
    // 0x1586a0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1586a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1586a4: 0x1064000a  beq         $v1, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1586A4u;
    {
        const bool branch_taken_0x1586a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1586a4) {
            ctx->pc = 0x1586D0u;
            goto label_1586d0;
        }
    }
    ctx->pc = 0x1586ACu;
    // 0x1586ac: 0x10740010  beq         $v1, $s4, . + 4 + (0x10 << 2)
    ctx->pc = 0x1586ACu;
    {
        const bool branch_taken_0x1586ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 20));
        if (branch_taken_0x1586ac) {
            ctx->pc = 0x1586F0u;
            goto label_1586f0;
        }
    }
    ctx->pc = 0x1586B4u;
    // 0x1586b4: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1586B4u;
    {
        const bool branch_taken_0x1586b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1586B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1586B4u;
            // 0x1586b8: 0x230102b  sltu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1586b4) {
            ctx->pc = 0x158724u;
            goto label_158724;
        }
    }
    ctx->pc = 0x1586BCu;
    // 0x1586bc: 0x0  nop
    ctx->pc = 0x1586bcu;
    // NOP
label_1586c0:
    // 0x1586c0: 0x50430017  beql        $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1586C0u;
    {
        const bool branch_taken_0x1586c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1586c0) {
            ctx->pc = 0x1586C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1586C0u;
            // 0x1586c4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158720u;
            goto label_158720;
        }
    }
    ctx->pc = 0x1586C8u;
    // 0x1586c8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1586C8u;
    {
        const bool branch_taken_0x1586c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1586CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1586C8u;
            // 0x1586cc: 0x230102b  sltu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1586c8) {
            ctx->pc = 0x158724u;
            goto label_158724;
        }
    }
    ctx->pc = 0x1586D0u;
label_1586d0:
    // 0x1586d0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1586D0u;
    {
        const bool branch_taken_0x1586d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1586d0) {
            ctx->pc = 0x1586E0u;
            goto label_1586e0;
        }
    }
    ctx->pc = 0x1586D8u;
    // 0x1586d8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1586D8u;
    {
        const bool branch_taken_0x1586d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1586DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1586D8u;
            // 0x1586dc: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1586d8) {
            ctx->pc = 0x158720u;
            goto label_158720;
        }
    }
    ctx->pc = 0x1586E0u;
label_1586e0:
    // 0x1586e0: 0x10520010  beq         $v0, $s2, . + 4 + (0x10 << 2)
    ctx->pc = 0x1586E0u;
    {
        const bool branch_taken_0x1586e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        ctx->pc = 0x1586E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1586E0u;
            // 0x1586e4: 0x230102b  sltu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1586e0) {
            ctx->pc = 0x158724u;
            goto label_158724;
        }
    }
    ctx->pc = 0x1586E8u;
    // 0x1586e8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1586E8u;
    {
        const bool branch_taken_0x1586e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1586ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1586E8u;
            // 0x1586ec: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1586e8) {
            ctx->pc = 0x158724u;
            goto label_158724;
        }
    }
    ctx->pc = 0x1586F0u;
label_1586f0:
    // 0x1586f0: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1586F0u;
    {
        const bool branch_taken_0x1586f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1586f0) {
            ctx->pc = 0x1586F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1586F0u;
            // 0x1586f4: 0x38420001  xori        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
            ctx->pc = 0x158718u;
            goto label_158718;
        }
    }
    ctx->pc = 0x1586F8u;
    // 0x1586f8: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x1586F8u;
    SET_GPR_U32(ctx, 31, 0x158700u);
    ctx->pc = 0x1586FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1586F8u;
            // 0x1586fc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158700u; }
        if (ctx->pc != 0x158700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158700u; }
        if (ctx->pc != 0x158700u) { return; }
    }
    ctx->pc = 0x158700u;
label_158700:
    // 0x158700: 0x2621824  and         $v1, $s3, $v0
    ctx->pc = 0x158700u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x158704: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x158704u;
    {
        const bool branch_taken_0x158704 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x158708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158704u;
            // 0x158708: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158704) {
            ctx->pc = 0x158730u;
            goto label_158730;
        }
    }
    ctx->pc = 0x15870Cu;
    // 0x15870c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15870Cu;
    {
        const bool branch_taken_0x15870c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15870Cu;
            // 0x158710: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15870c) {
            ctx->pc = 0x158720u;
            goto label_158720;
        }
    }
    ctx->pc = 0x158714u;
    // 0x158714: 0x0  nop
    ctx->pc = 0x158714u;
    // NOP
label_158718:
    // 0x158718: 0x240182d  daddu       $v1, $s2, $zero
    ctx->pc = 0x158718u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15871c: 0x82180a  movz        $v1, $a0, $v0
    ctx->pc = 0x15871cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
label_158720:
    // 0x158720: 0x230102b  sltu        $v0, $s1, $s0
    ctx->pc = 0x158720u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
label_158724:
    // 0x158724: 0x1440ffda  bnez        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x158724u;
    {
        const bool branch_taken_0x158724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158724u;
            // 0x158728: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158724) {
            ctx->pc = 0x158690u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_158690;
        }
    }
    ctx->pc = 0x15872Cu;
label_15872c:
    // 0x15872c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15872cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_158730:
    // 0x158730: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x158730u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158734: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158734u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158738: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x158738u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15873c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15873cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x158740: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x158740u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x158744: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x158744u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x158748: 0x3e00008  jr          $ra
    ctx->pc = 0x158748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15874Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158748u;
            // 0x15874c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158690u: goto label_158690;
            case 0x1586C0u: goto label_1586c0;
            case 0x1586D0u: goto label_1586d0;
            case 0x1586E0u: goto label_1586e0;
            case 0x1586F0u: goto label_1586f0;
            case 0x158700u: goto label_158700;
            case 0x158718u: goto label_158718;
            case 0x158720u: goto label_158720;
            case 0x158724u: goto label_158724;
            case 0x15872Cu: goto label_15872c;
            case 0x158730u: goto label_158730;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158750u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130108
// Address: 0x130108 - 0x130218
void sub_00130108_0x130108(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130108_0x130108");
#endif

    switch (ctx->pc) {
        case 0x130144u: goto label_130144;
        case 0x1301c4u: goto label_1301c4;
        case 0x1301dcu: goto label_1301dc;
        default: break;
    }

    ctx->pc = 0x130108u;

    // 0x130108: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x130108u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13010c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13010cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130110: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x130110u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130114: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x130114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130118: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x130118u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13011c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13011cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130120: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x130120u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130124: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x130124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x130128: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x130128u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13012c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13012cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x130130: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x130130u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130134: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x130134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x130138: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x130138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x13013c: 0xc049938  jal         func_1264E0
    ctx->pc = 0x13013Cu;
    SET_GPR_U32(ctx, 31, 0x130144u);
    ctx->pc = 0x130140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13013Cu;
            // 0x130140: 0x24150001  addiu       $s5, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130144u; }
        if (ctx->pc != 0x130144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130144u; }
        if (ctx->pc != 0x130144u) { return; }
    }
    ctx->pc = 0x130144u;
label_130144:
    // 0x130144: 0x260707ff  addiu       $a3, $s0, 0x7FF
    ctx->pc = 0x130144u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 2047));
    // 0x130148: 0x2a030000  slti        $v1, $s0, 0x0
    ctx->pc = 0x130148u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13014c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x13014cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130150: 0x3c06000f  lui         $a2, 0xF
    ctx->pc = 0x130150u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)15 << 16));
    // 0x130154: 0xe3100b  movn        $v0, $a3, $v1
    ctx->pc = 0x130154u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 7));
    // 0x130158: 0x24070200  addiu       $a3, $zero, 0x200
    ctx->pc = 0x130158u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x13015c: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x13015cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x130160: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x130160u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x130164: 0x21ac0  sll         $v1, $v0, 11
    ctx->pc = 0x130164u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x130168: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130168u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13016c: 0x2031823  subu        $v1, $s0, $v1
    ctx->pc = 0x13016cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x130170: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x130170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130174: 0x24480001  addiu       $t0, $v0, 0x1
    ctx->pc = 0x130174u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x130178: 0xae710008  sw          $s1, 0x8($s3)
    ctx->pc = 0x130178u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 17));
    // 0x13017c: 0xae72000c  sw          $s2, 0xC($s3)
    ctx->pc = 0x13017cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 18));
    // 0x130180: 0xae670028  sw          $a3, 0x28($s3)
    ctx->pc = 0x130180u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 40), GPR_U32(ctx, 7));
    // 0x130184: 0xae660058  sw          $a2, 0x58($s3)
    ctx->pc = 0x130184u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 88), GPR_U32(ctx, 6));
    // 0x130188: 0xa2750001  sb          $s5, 0x1($s3)
    ctx->pc = 0x130188u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 21));
    // 0x13018c: 0xa2600002  sb          $zero, 0x2($s3)
    ctx->pc = 0x13018cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x130190: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x130190u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
    // 0x130194: 0xae62002c  sw          $v0, 0x2C($s3)
    ctx->pc = 0x130194u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 44), GPR_U32(ctx, 2));
    // 0x130198: 0xae700010  sw          $s0, 0x10($s3)
    ctx->pc = 0x130198u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 16));
    // 0x13019c: 0x18600002  blez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x13019Cu;
    {
        const bool branch_taken_0x13019c = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1301A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13019Cu;
            // 0x1301a0: 0xae600054  sw          $zero, 0x54($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 84), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13019c) {
            ctx->pc = 0x1301A8u;
            goto label_1301a8;
        }
    }
    ctx->pc = 0x1301A4u;
    // 0x1301a4: 0xae68002c  sw          $t0, 0x2C($s3)
    ctx->pc = 0x1301a4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 44), GPR_U32(ctx, 8));
label_1301a8:
    // 0x1301a8: 0x8e620004  lw          $v0, 0x4($s3)
    ctx->pc = 0x1301a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1301ac: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x1301ACu;
    {
        const bool branch_taken_0x1301ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1301ac) {
            ctx->pc = 0x1301B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1301ACu;
            // 0x1301b0: 0xa2750000  sb          $s5, 0x0($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1301F0u;
            goto label_1301f0;
        }
    }
    ctx->pc = 0x1301B4u;
    // 0x1301b4: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1301b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1301b8: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1301b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1301bc: 0x40f809  jalr        $v0
    ctx->pc = 0x1301BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1301C4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1301C4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130144u: goto label_130144;
            case 0x1301A8u: goto label_1301a8;
            case 0x1301C4u: goto label_1301c4;
            case 0x1301DCu: goto label_1301dc;
            case 0x1301F0u: goto label_1301f0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1301C4u; }
            if (ctx->pc != 0x1301C4u) { return; }
        }
        }
    }
    ctx->pc = 0x1301C4u;
label_1301c4:
    // 0x1301c4: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1301c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1301c8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1301c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1301cc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1301ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1301d0: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1301d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1301d4: 0x40f809  jalr        $v0
    ctx->pc = 0x1301D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1301DCu);
        ctx->pc = 0x1301D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1301D4u;
            // 0x1301d8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1301DCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130144u: goto label_130144;
            case 0x1301A8u: goto label_1301a8;
            case 0x1301C4u: goto label_1301c4;
            case 0x1301DCu: goto label_1301dc;
            case 0x1301F0u: goto label_1301f0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1301DCu; }
            if (ctx->pc != 0x1301DCu) { return; }
        }
        }
    }
    ctx->pc = 0x1301DCu;
label_1301dc:
    // 0x1301dc: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1301dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1301e0: 0xae700018  sw          $s0, 0x18($s3)
    ctx->pc = 0x1301e0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 24), GPR_U32(ctx, 16));
    // 0x1301e4: 0xae70003c  sw          $s0, 0x3C($s3)
    ctx->pc = 0x1301e4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 16));
    // 0x1301e8: 0xae700014  sw          $s0, 0x14($s3)
    ctx->pc = 0x1301e8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 16));
    // 0x1301ec: 0xa2750000  sb          $s5, 0x0($s3)
    ctx->pc = 0x1301ecu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 21));
label_1301f0:
    // 0x1301f0: 0xa2600040  sb          $zero, 0x40($s3)
    ctx->pc = 0x1301f0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 64), (uint8_t)GPR_U32(ctx, 0));
    // 0x1301f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1301f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1301f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1301f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1301fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1301fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x130200: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x130200u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x130204: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x130204u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x130208: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x130208u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13020c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13020cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x130210: 0x804993e  j           func_1264F8
    ctx->pc = 0x130210u;
    ctx->pc = 0x130214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130210u;
            // 0x130214: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130218u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

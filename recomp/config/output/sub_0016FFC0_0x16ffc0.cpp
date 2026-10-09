#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FFC0
// Address: 0x16ffc0 - 0x170120
void sub_0016FFC0_0x16ffc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FFC0_0x16ffc0");
#endif

    switch (ctx->pc) {
        case 0x16ffecu: goto label_16ffec;
        case 0x1700f0u: goto label_1700f0;
        case 0x1700fcu: goto label_1700fc;
        case 0x170108u: goto label_170108;
        default: break;
    }

    ctx->pc = 0x16ffc0u;

    // 0x16ffc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16ffc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16ffc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16ffc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16ffc8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16ffc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ffcc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16ffccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16ffd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16ffd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ffd4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16ffd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16ffd8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16ffd8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ffdc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16ffdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16ffe0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16ffe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16ffe4: 0xc05c146  jal         func_170518
    ctx->pc = 0x16FFE4u;
    SET_GPR_U32(ctx, 31, 0x16FFECu);
    ctx->pc = 0x16FFE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FFE4u;
            // 0x16ffe8: 0x8e331b30  lw          $s3, 0x1B30($s1) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6960)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170518u;
    if (runtime->hasFunction(0x170518u)) {
        auto targetFn = runtime->lookupFunction(0x170518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FFECu; }
        if (ctx->pc != 0x16FFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170518_0x170518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FFECu; }
        if (ctx->pc != 0x16FFECu) { return; }
    }
    ctx->pc = 0x16FFECu;
label_16ffec:
    // 0x16ffec: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16ffecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16fff0: 0x2605002c  addiu       $a1, $s0, 0x2C
    ctx->pc = 0x16fff0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    // 0x16fff4: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x16fff4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x16fff8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x16fff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x16fffc: 0x8ca40018  lw          $a0, 0x18($a1)
    ctx->pc = 0x16fffcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x170000: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x170000u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x170004: 0xac440010  sw          $a0, 0x10($v0)
    ctx->pc = 0x170004u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 4));
    // 0x170008: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x170008u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x17000c: 0x8e270038  lw          $a3, 0x38($s1)
    ctx->pc = 0x17000cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x170010: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x170010u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x170014: 0x8e080028  lw          $t0, 0x28($s0)
    ctx->pc = 0x170014u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x170018: 0xac430004  sw          $v1, 0x4($v0)
    ctx->pc = 0x170018u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
    // 0x17001c: 0x8e060008  lw          $a2, 0x8($s0)
    ctx->pc = 0x17001cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x170020: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x170020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x170024: 0x8ca90038  lw          $t1, 0x38($a1)
    ctx->pc = 0x170024u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 56)));
    // 0x170028: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x170028u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x17002c: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17002cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x170030: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x170030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x170034: 0xae700070  sw          $s0, 0x70($s3)
    ctx->pc = 0x170034u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 112), GPR_U32(ctx, 16));
    // 0x170038: 0xac43000c  sw          $v1, 0xC($v0)
    ctx->pc = 0x170038u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 3));
    // 0x17003c: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x17003cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x170040: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x170040u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x170044: 0xac460020  sw          $a2, 0x20($v0)
    ctx->pc = 0x170044u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 6));
    // 0x170048: 0xac430014  sw          $v1, 0x14($v0)
    ctx->pc = 0x170048u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 3));
    // 0x17004c: 0xac480038  sw          $t0, 0x38($v0)
    ctx->pc = 0x17004cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 8));
    // 0x170050: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x170050u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x170054: 0xac430018  sw          $v1, 0x18($v0)
    ctx->pc = 0x170054u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x170058: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x170058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x17005c: 0xac440024  sw          $a0, 0x24($v0)
    ctx->pc = 0x17005cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 4));
    // 0x170060: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x170060u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x170064: 0xac430028  sw          $v1, 0x28($v0)
    ctx->pc = 0x170064u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 40), GPR_U32(ctx, 3));
    // 0x170068: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x170068u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x17006c: 0xac44002c  sw          $a0, 0x2C($v0)
    ctx->pc = 0x17006cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 44), GPR_U32(ctx, 4));
    // 0x170070: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x170070u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x170074: 0xac430030  sw          $v1, 0x30($v0)
    ctx->pc = 0x170074u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 3));
    // 0x170078: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x170078u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x17007c: 0xac440034  sw          $a0, 0x34($v0)
    ctx->pc = 0x17007cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 4));
    // 0x170080: 0x8ca30040  lw          $v1, 0x40($a1)
    ctx->pc = 0x170080u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x170084: 0x8ca40050  lw          $a0, 0x50($a1)
    ctx->pc = 0x170084u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 80)));
    // 0x170088: 0xac430044  sw          $v1, 0x44($v0)
    ctx->pc = 0x170088u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 68), GPR_U32(ctx, 3));
    // 0x17008c: 0x8ca6003c  lw          $a2, 0x3C($a1)
    ctx->pc = 0x17008cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 60)));
    // 0x170090: 0x8ca30044  lw          $v1, 0x44($a1)
    ctx->pc = 0x170090u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 68)));
    // 0x170094: 0x8ca7004c  lw          $a3, 0x4C($a1)
    ctx->pc = 0x170094u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x170098: 0xac430048  sw          $v1, 0x48($v0)
    ctx->pc = 0x170098u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 3));
    // 0x17009c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17009cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1700a0: 0x8ca30048  lw          $v1, 0x48($a1)
    ctx->pc = 0x1700a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 72)));
    // 0x1700a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1700a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1700a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1700a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1700ac: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1700acu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1700b0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1700b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1700b4: 0xac49003c  sw          $t1, 0x3C($v0)
    ctx->pc = 0x1700b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 9));
    // 0x1700b8: 0xac440054  sw          $a0, 0x54($v0)
    ctx->pc = 0x1700b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 84), GPR_U32(ctx, 4));
    // 0x1700bc: 0xac460040  sw          $a2, 0x40($v0)
    ctx->pc = 0x1700bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 64), GPR_U32(ctx, 6));
    // 0x1700c0: 0xac43004c  sw          $v1, 0x4C($v0)
    ctx->pc = 0x1700c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 3));
    // 0x1700c4: 0xac470050  sw          $a3, 0x50($v0)
    ctx->pc = 0x1700c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 80), GPR_U32(ctx, 7));
    // 0x1700c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1700C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1700CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1700C8u;
            // 0x1700cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FFECu: goto label_16ffec;
            case 0x1700F0u: goto label_1700f0;
            case 0x1700FCu: goto label_1700fc;
            case 0x170108u: goto label_170108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1700D0u;
    // 0x1700d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1700d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1700d4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1700d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1700d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1700d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1700dc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1700dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1700e0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1700e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1700e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1700e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1700e8: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x1700E8u;
    SET_GPR_U32(ctx, 31, 0x1700F0u);
    ctx->pc = 0x1700ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1700E8u;
            // 0x1700ec: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700F0u; }
        if (ctx->pc != 0x1700F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700F0u; }
        if (ctx->pc != 0x1700F0u) { return; }
    }
    ctx->pc = 0x1700F0u;
label_1700f0:
    // 0x1700f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1700f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1700f4: 0xc05c048  jal         func_170120
    ctx->pc = 0x1700F4u;
    SET_GPR_U32(ctx, 31, 0x1700FCu);
    ctx->pc = 0x1700F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1700F4u;
            // 0x1700f8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170120u;
    if (runtime->hasFunction(0x170120u)) {
        auto targetFn = runtime->lookupFunction(0x170120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700FCu; }
        if (ctx->pc != 0x1700FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170120_0x170120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700FCu; }
        if (ctx->pc != 0x1700FCu) { return; }
    }
    ctx->pc = 0x1700FCu;
label_1700fc:
    // 0x1700fc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1700fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170100: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x170100u;
    SET_GPR_U32(ctx, 31, 0x170108u);
    ctx->pc = 0x170104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170100u;
            // 0x170104: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170108u; }
        if (ctx->pc != 0x170108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170108u; }
        if (ctx->pc != 0x170108u) { return; }
    }
    ctx->pc = 0x170108u;
label_170108:
    // 0x170108: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x170108u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17010c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17010cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170110: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x170110u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170114: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x170114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x170118: 0x3e00008  jr          $ra
    ctx->pc = 0x170118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17011Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170118u;
            // 0x17011c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FFECu: goto label_16ffec;
            case 0x1700F0u: goto label_1700f0;
            case 0x1700FCu: goto label_1700fc;
            case 0x170108u: goto label_170108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

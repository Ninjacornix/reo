#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F9F0
// Address: 0x13f9f0 - 0x13ffb8
void sub_0013F9F0_0x13f9f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F9F0_0x13f9f0");
#endif

    switch (ctx->pc) {
        case 0x13fa04u: goto label_13fa04;
        case 0x13fa74u: goto label_13fa74;
        case 0x13fab4u: goto label_13fab4;
        case 0x13fbd8u: goto label_13fbd8;
        case 0x13fc34u: goto label_13fc34;
        case 0x13fc88u: goto label_13fc88;
        case 0x13fcc8u: goto label_13fcc8;
        case 0x13fd28u: goto label_13fd28;
        case 0x13fd94u: goto label_13fd94;
        case 0x13fe0cu: goto label_13fe0c;
        case 0x13fe94u: goto label_13fe94;
        case 0x13fec0u: goto label_13fec0;
        case 0x13ff1cu: goto label_13ff1c;
        case 0x13ff8cu: goto label_13ff8c;
        case 0x13ff94u: goto label_13ff94;
        default: break;
    }

    ctx->pc = 0x13f9f0u;

    // 0x13f9f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f9f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f9f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f9f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f9f8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13f9f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13f9fc: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F9FCu;
    SET_GPR_U32(ctx, 31, 0x13FA04u);
    ctx->pc = 0x13FA00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9FCu;
            // 0x13fa00: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FA04u; }
        if (ctx->pc != 0x13FA04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FA04u; }
        if (ctx->pc != 0x13FA04u) { return; }
    }
    ctx->pc = 0x13FA04u;
label_13fa04:
    // 0x13fa04: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fa04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fa08: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x13fa08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x13fa0c: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x13fa0cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x13fa10: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x13fa10u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x13fa14: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x13fa14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x13fa18: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x13fa18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x13fa1c: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x13fa1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x13fa20: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x13fa20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x13fa24: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x13fa24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x13fa28: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13fa28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fa2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fa2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fa30: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FA30u;
    ctx->pc = 0x13FA34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA30u;
            // 0x13fa34: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FA38u;
    // 0x13fa38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13fa38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13fa3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13fa3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13fa40: 0x14a20003  bne         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13FA40u;
    {
        const bool branch_taken_0x13fa40 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x13FA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA40u;
            // 0x13fa44: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fa40) {
            ctx->pc = 0x13FA50u;
            goto label_13fa50;
        }
    }
    ctx->pc = 0x13FA48u;
    // 0x13fa48: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x13FA48u;
    {
        const bool branch_taken_0x13fa48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA48u;
            // 0x13fa4c: 0x8c82000c  lw          $v0, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fa48) {
            ctx->pc = 0x13FA78u;
            goto label_13fa78;
        }
    }
    ctx->pc = 0x13FA50u;
label_13fa50:
    // 0x13fa50: 0x54a00003  bnel        $a1, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x13FA50u;
    {
        const bool branch_taken_0x13fa50 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x13fa50) {
            ctx->pc = 0x13FA54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA50u;
            // 0x13fa54: 0x8c820038  lw          $v0, 0x38($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FA60u;
            goto label_13fa60;
        }
    }
    ctx->pc = 0x13FA58u;
    // 0x13fa58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FA58u;
    {
        const bool branch_taken_0x13fa58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA58u;
            // 0x13fa5c: 0x8c820010  lw          $v0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fa58) {
            ctx->pc = 0x13FA78u;
            goto label_13fa78;
        }
    }
    ctx->pc = 0x13FA60u;
label_13fa60:
    // 0x13fa60: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x13FA60u;
    {
        const bool branch_taken_0x13fa60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fa60) {
            ctx->pc = 0x13FA64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA60u;
            // 0x13fa64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FA78u;
            goto label_13fa78;
        }
    }
    ctx->pc = 0x13FA68u;
    // 0x13fa68: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x13fa68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x13fa6c: 0x40f809  jalr        $v0
    ctx->pc = 0x13FA6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FA74u);
        ctx->pc = 0x13FA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA6Cu;
            // 0x13fa70: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FA74u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FA74u; }
            if (ctx->pc != 0x13FA74u) { return; }
        }
        }
    }
    ctx->pc = 0x13FA74u;
label_13fa74:
    // 0x13fa74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13fa74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13fa78:
    // 0x13fa78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13fa78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fa7c: 0x3e00008  jr          $ra
    ctx->pc = 0x13FA7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FA80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FA7Cu;
            // 0x13fa80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FA84u;
    // 0x13fa84: 0x0  nop
    ctx->pc = 0x13fa84u;
    // NOP
    // 0x13fa88: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13fa88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13fa8c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13fa8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13fa90: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13fa90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fa94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fa94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fa98: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13fa98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fa9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fa9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13faa0: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x13faa0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13faa4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13faa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13faa8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13faa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13faac: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FAACu;
    SET_GPR_U32(ctx, 31, 0x13FAB4u);
    ctx->pc = 0x13FAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FAACu;
            // 0x13fab0: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FAB4u; }
        if (ctx->pc != 0x13FAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FAB4u; }
        if (ctx->pc != 0x13FAB4u) { return; }
    }
    ctx->pc = 0x13FAB4u;
label_13fab4:
    // 0x13fab4: 0x16400020  bnez        $s2, . + 4 + (0x20 << 2)
    ctx->pc = 0x13FAB4u;
    {
        const bool branch_taken_0x13fab4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13FAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FAB4u;
            // 0x13fab8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fab4) {
            ctx->pc = 0x13FB38u;
            goto label_13fb38;
        }
    }
    ctx->pc = 0x13FABCu;
    // 0x13fabc: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x13fabcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13fac0: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fac4: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x13fac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13fac8: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x13fac8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13facc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13faccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fad0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13fad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fad4: 0x8e06001c  lw          $a2, 0x1C($s0)
    ctx->pc = 0x13fad4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fad8: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x13fad8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13fadc: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x13fadcu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x13fae0: 0x53202a  slt         $a0, $v0, $s3
    ctx->pc = 0x13fae0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13fae4: 0x264100a  movz        $v0, $s3, $a0
    ctx->pc = 0x13fae4u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 19));
    // 0x13fae8: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x13fae8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x13faec: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x13faecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13faf0: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x13faf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13faf4: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x13faf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13faf8: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x13faf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x13fafc: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x13fafcu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fb00: 0xae260000  sw          $a2, 0x0($s1)
    ctx->pc = 0x13fb00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 6));
    // 0x13fb04: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FB04u;
    {
        const bool branch_taken_0x13fb04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fb04) {
            ctx->pc = 0x13FB08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB04u;
            // 0x13fb08: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FB0Cu;
            goto label_13fb0c;
        }
    }
    ctx->pc = 0x13FB0Cu;
label_13fb0c:
    // 0x13fb0c: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x13fb0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13fb10: 0x8e030028  lw          $v1, 0x28($s0)
    ctx->pc = 0x13fb10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13fb14: 0x2810  mfhi        $a1
    ctx->pc = 0x13fb14u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x13fb18: 0xae050014  sw          $a1, 0x14($s0)
    ctx->pc = 0x13fb18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 5));
    // 0x13fb1c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fb20: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13fb20u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fb24: 0xae040010  sw          $a0, 0x10($s0)
    ctx->pc = 0x13fb24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 4));
    // 0x13fb28: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fb28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fb2c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13fb2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13fb30: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x13FB30u;
    {
        const bool branch_taken_0x13fb30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB30u;
            // 0x13fb34: 0xae030028  sw          $v1, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fb30) {
            ctx->pc = 0x13FBD8u;
            goto label_13fbd8;
        }
    }
    ctx->pc = 0x13FB38u;
label_13fb38:
    // 0x13fb38: 0x56420021  bnel        $s2, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13FB38u;
    {
        const bool branch_taken_0x13fb38 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13fb38) {
            ctx->pc = 0x13FB3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB38u;
            // 0x13fb3c: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FBC0u;
            goto label_13fbc0;
        }
    }
    ctx->pc = 0x13FB40u;
    // 0x13fb40: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x13fb40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13fb44: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fb44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fb48: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x13fb48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13fb4c: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x13fb4cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fb50: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13fb50u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fb54: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13fb54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fb58: 0x8e06001c  lw          $a2, 0x1C($s0)
    ctx->pc = 0x13fb58u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fb5c: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x13fb5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13fb60: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x13fb60u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x13fb64: 0x53202a  slt         $a0, $v0, $s3
    ctx->pc = 0x13fb64u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13fb68: 0x264100a  movz        $v0, $s3, $a0
    ctx->pc = 0x13fb68u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 19));
    // 0x13fb6c: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x13fb6cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x13fb70: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x13fb70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13fb74: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x13fb74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fb78: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x13fb78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fb7c: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x13fb7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x13fb80: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x13fb80u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fb84: 0xae260000  sw          $a2, 0x0($s1)
    ctx->pc = 0x13fb84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 6));
    // 0x13fb88: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FB88u;
    {
        const bool branch_taken_0x13fb88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fb88) {
            ctx->pc = 0x13FB8Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FB88u;
            // 0x13fb8c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FB90u;
            goto label_13fb90;
        }
    }
    ctx->pc = 0x13FB90u;
label_13fb90:
    // 0x13fb90: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x13fb90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fb94: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x13fb94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x13fb98: 0x2810  mfhi        $a1
    ctx->pc = 0x13fb98u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x13fb9c: 0xae050018  sw          $a1, 0x18($s0)
    ctx->pc = 0x13fb9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 5));
    // 0x13fba0: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fba4: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13fba4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fba8: 0xae04000c  sw          $a0, 0xC($s0)
    ctx->pc = 0x13fba8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 4));
    // 0x13fbac: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fbacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fbb0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13fbb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13fbb4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13FBB4u;
    {
        const bool branch_taken_0x13fbb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FBB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBB4u;
            // 0x13fbb8: 0xae030030  sw          $v1, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fbb4) {
            ctx->pc = 0x13FBD8u;
            goto label_13fbd8;
        }
    }
    ctx->pc = 0x13FBBCu;
    // 0x13fbbc: 0x0  nop
    ctx->pc = 0x13fbbcu;
    // NOP
label_13fbc0:
    // 0x13fbc0: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13fbc0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13fbc4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FBC4u;
    {
        const bool branch_taken_0x13fbc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FBC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBC4u;
            // 0x13fbc8: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fbc4) {
            ctx->pc = 0x13FBD8u;
            goto label_13fbd8;
        }
    }
    ctx->pc = 0x13FBCCu;
    // 0x13fbcc: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fbccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fbd0: 0x40f809  jalr        $v0
    ctx->pc = 0x13FBD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FBD8u);
        ctx->pc = 0x13FBD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBD0u;
            // 0x13fbd4: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FBD8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FBD8u; }
            if (ctx->pc != 0x13FBD8u) { return; }
        }
        }
    }
    ctx->pc = 0x13FBD8u;
label_13fbd8:
    // 0x13fbd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fbd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fbdc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fbdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fbe0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fbe0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fbe4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13fbe4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fbe8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13fbe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13fbec: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FBECu;
    ctx->pc = 0x13FBF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FBECu;
            // 0x13fbf0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FBF4u;
    // 0x13fbf4: 0x0  nop
    ctx->pc = 0x13fbf4u;
    // NOP
    // 0x13fbf8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13fbf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13fbfc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fbfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fc00: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13fc00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fc04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fc04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13fc08: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13fc08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fc0c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13fc0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13fc10: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13fc10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13fc14: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fc14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc18: 0x18400049  blez        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x13FC18u;
    {
        const bool branch_taken_0x13fc18 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13FC1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC18u;
            // 0x13fc1c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fc18) {
            ctx->pc = 0x13FD40u;
            goto label_13fd40;
        }
    }
    ctx->pc = 0x13FC20u;
    // 0x13fc20: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13fc20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fc24: 0x50400047  beql        $v0, $zero, . + 4 + (0x47 << 2)
    ctx->pc = 0x13FC24u;
    {
        const bool branch_taken_0x13fc24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fc24) {
            ctx->pc = 0x13FC28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC24u;
            // 0x13fc28: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FD44u;
            goto label_13fd44;
        }
    }
    ctx->pc = 0x13FC2Cu;
    // 0x13fc2c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FC2Cu;
    SET_GPR_U32(ctx, 31, 0x13FC34u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC34u; }
        if (ctx->pc != 0x13FC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC34u; }
        if (ctx->pc != 0x13FC34u) { return; }
    }
    ctx->pc = 0x13FC34u;
label_13fc34:
    // 0x13fc34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13fc34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13fc38: 0x16420029  bne         $s2, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x13FC38u;
    {
        const bool branch_taken_0x13fc38 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13fc38) {
            ctx->pc = 0x13FCE0u;
            goto label_13fce0;
        }
    }
    ctx->pc = 0x13FC40u;
    // 0x13fc40: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13fc40u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fc44: 0x8e09001c  lw          $t1, 0x1C($s0)
    ctx->pc = 0x13fc44u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fc48: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x13fc48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fc4c: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x13fc4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc50: 0xa93823  subu        $a3, $a1, $t1
    ctx->pc = 0x13fc50u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x13fc54: 0x8e060024  lw          $a2, 0x24($s0)
    ctx->pc = 0x13fc54u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13fc58: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13fc58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13fc5c: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x13fc5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13fc60: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x13FC60u;
    {
        const bool branch_taken_0x13fc60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC60u;
            // 0x13fc64: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fc60) {
            ctx->pc = 0x13FC90u;
            goto label_13fc90;
        }
    }
    ctx->pc = 0x13FC68u;
    // 0x13fc68: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fc68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc6c: 0xc73023  subu        $a2, $a2, $a3
    ctx->pc = 0x13fc6cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x13fc70: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13fc70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fc74: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x13fc74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13fc78: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x13fc78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x13fc7c: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x13fc7cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x13fc80: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x13FC80u;
    SET_GPR_U32(ctx, 31, 0x13FC88u);
    ctx->pc = 0x13FC84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FC80u;
            // 0x13fc84: 0x1242021  addu        $a0, $t1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC88u; }
        if (ctx->pc != 0x13FC88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FC88u; }
        if (ctx->pc != 0x13FC88u) { return; }
    }
    ctx->pc = 0x13FC88u;
label_13fc88:
    // 0x13fc88: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13fc88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fc8c: 0x8e09001c  lw          $t1, 0x1C($s0)
    ctx->pc = 0x13fc8cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
label_13fc90:
    // 0x13fc90: 0x8e280004  lw          $t0, 0x4($s1)
    ctx->pc = 0x13fc90u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fc94: 0xa91823  subu        $v1, $a1, $t1
    ctx->pc = 0x13fc94u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x13fc98: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13fc98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fc9c: 0x683821  addu        $a3, $v1, $t0
    ctx->pc = 0x13fc9cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x13fca0: 0x87102a  slt         $v0, $a0, $a3
    ctx->pc = 0x13fca0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x13fca4: 0x5040000a  beql        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x13FCA4u;
    {
        const bool branch_taken_0x13fca4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fca4) {
            ctx->pc = 0x13FCA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCA4u;
            // 0x13fca8: 0x8e020034  lw          $v0, 0x34($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FCD0u;
            goto label_13fcd0;
        }
    }
    ctx->pc = 0x13FCACu;
    // 0x13fcac: 0xe43023  subu        $a2, $a3, $a0
    ctx->pc = 0x13fcacu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x13fcb0: 0x120202d  daddu       $a0, $t1, $zero
    ctx->pc = 0x13fcb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fcb4: 0x106102a  slt         $v0, $t0, $a2
    ctx->pc = 0x13fcb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13fcb8: 0x102300b  movn        $a2, $t0, $v0
    ctx->pc = 0x13fcb8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 8));
    // 0x13fcbc: 0xe62823  subu        $a1, $a3, $a2
    ctx->pc = 0x13fcbcu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x13fcc0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x13FCC0u;
    SET_GPR_U32(ctx, 31, 0x13FCC8u);
    ctx->pc = 0x13FCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCC0u;
            // 0x13fcc4: 0x852821  addu        $a1, $a0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FCC8u; }
        if (ctx->pc != 0x13FCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FCC8u; }
        if (ctx->pc != 0x13FCC8u) { return; }
    }
    ctx->pc = 0x13FCC8u;
label_13fcc8:
    // 0x13fcc8: 0x8e280004  lw          $t0, 0x4($s1)
    ctx->pc = 0x13fcc8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fccc: 0x8e020034  lw          $v0, 0x34($s0)
    ctx->pc = 0x13fcccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
label_13fcd0:
    // 0x13fcd0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x13fcd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x13fcd4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x13FCD4u;
    {
        const bool branch_taken_0x13fcd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FCD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCD4u;
            // 0x13fcd8: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fcd4) {
            ctx->pc = 0x13FD28u;
            goto label_13fd28;
        }
    }
    ctx->pc = 0x13FCDCu;
    // 0x13fcdc: 0x0  nop
    ctx->pc = 0x13fcdcu;
    // NOP
label_13fce0:
    // 0x13fce0: 0x5640000b  bnel        $s2, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x13FCE0u;
    {
        const bool branch_taken_0x13fce0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x13fce0) {
            ctx->pc = 0x13FCE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FCE0u;
            // 0x13fce4: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FD10u;
            goto label_13fd10;
        }
    }
    ctx->pc = 0x13FCE8u;
    // 0x13fce8: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fce8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fcec: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x13fcecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13fcf0: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x13fcf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13fcf4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13fcf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fcf8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x13fcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x13fcfc: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fcfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fd00: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x13fd00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x13fd04: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13FD04u;
    {
        const bool branch_taken_0x13fd04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FD08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD04u;
            // 0x13fd08: 0xae04002c  sw          $a0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd04) {
            ctx->pc = 0x13FD28u;
            goto label_13fd28;
        }
    }
    ctx->pc = 0x13FD0Cu;
    // 0x13fd0c: 0x0  nop
    ctx->pc = 0x13fd0cu;
    // NOP
label_13fd10:
    // 0x13fd10: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13fd10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13fd14: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FD14u;
    {
        const bool branch_taken_0x13fd14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD14u;
            // 0x13fd18: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd14) {
            ctx->pc = 0x13FD28u;
            goto label_13fd28;
        }
    }
    ctx->pc = 0x13FD1Cu;
    // 0x13fd1c: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fd1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fd20: 0x40f809  jalr        $v0
    ctx->pc = 0x13FD20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FD28u);
        ctx->pc = 0x13FD24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD20u;
            // 0x13fd24: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FD28u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FD28u; }
            if (ctx->pc != 0x13FD28u) { return; }
        }
        }
    }
    ctx->pc = 0x13FD28u;
label_13fd28:
    // 0x13fd28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fd28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fd2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fd2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fd30: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fd30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fd34: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13fd34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fd38: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FD38u;
    ctx->pc = 0x13FD3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD38u;
            // 0x13fd3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FD40u;
label_13fd40:
    // 0x13fd40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fd40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13fd44:
    // 0x13fd44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fd44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fd48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fd48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fd4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13fd4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fd50: 0x3e00008  jr          $ra
    ctx->pc = 0x13FD50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD50u;
            // 0x13fd54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FD58u;
    // 0x13fd58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13fd58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13fd5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fd5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fd60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13fd60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fd64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fd64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13fd68: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13fd68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fd6c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13fd6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13fd70: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13fd70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13fd74: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13fd74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fd78: 0x18400057  blez        $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x13FD78u;
    {
        const bool branch_taken_0x13fd78 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13FD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD78u;
            // 0x13fd7c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd78) {
            ctx->pc = 0x13FED8u;
            goto label_13fed8;
        }
    }
    ctx->pc = 0x13FD80u;
    // 0x13fd80: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13fd80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fd84: 0x50400055  beql        $v0, $zero, . + 4 + (0x55 << 2)
    ctx->pc = 0x13FD84u;
    {
        const bool branch_taken_0x13fd84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fd84) {
            ctx->pc = 0x13FD88u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD84u;
            // 0x13fd88: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FEDCu;
            goto label_13fedc;
        }
    }
    ctx->pc = 0x13FD8Cu;
    // 0x13fd8c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FD8Cu;
    SET_GPR_U32(ctx, 31, 0x13FD94u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FD94u; }
        if (ctx->pc != 0x13FD94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FD94u; }
        if (ctx->pc != 0x13FD94u) { return; }
    }
    ctx->pc = 0x13FD94u;
label_13fd94:
    // 0x13fd94: 0x16400022  bnez        $s2, . + 4 + (0x22 << 2)
    ctx->pc = 0x13FD94u;
    {
        const bool branch_taken_0x13fd94 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13FD98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FD94u;
            // 0x13fd98: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fd94) {
            ctx->pc = 0x13FE20u;
            goto label_13fe20;
        }
    }
    ctx->pc = 0x13FD9Cu;
    // 0x13fd9c: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fd9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fda0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x13fda0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13fda4: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fda4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fda8: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FDA8u;
    {
        const bool branch_taken_0x13fda8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fda8) {
            ctx->pc = 0x13FDACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDA8u;
            // 0x13fdac: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FDB0u;
            goto label_13fdb0;
        }
    }
    ctx->pc = 0x13FDB0u;
label_13fdb0:
    // 0x13fdb0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13fdb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13fdb4: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x13fdb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fdb8: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x13fdb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x13fdbc: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x13fdbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fdc0: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x13fdc0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fdc4: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x13fdc4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x13fdc8: 0x3010  mfhi        $a2
    ctx->pc = 0x13fdc8u;
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x13fdcc: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x13fdccu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fdd0: 0x1810  mfhi        $v1
    ctx->pc = 0x13fdd0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x13fdd4: 0x54c30008  bnel        $a2, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13FDD4u;
    {
        const bool branch_taken_0x13fdd4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        if (branch_taken_0x13fdd4) {
            ctx->pc = 0x13FDD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDD4u;
            // 0x13fdd8: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FDF8u;
            goto label_13fdf8;
        }
    }
    ctx->pc = 0x13FDDCu;
    // 0x13fddc: 0xae060014  sw          $a2, 0x14($s0)
    ctx->pc = 0x13fddcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 6));
    // 0x13fde0: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x13fde0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13fde4: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fde4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fde8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13fde8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fdec: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FDECu;
    {
        const bool branch_taken_0x13fdec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FDF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDECu;
            // 0x13fdf0: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fdec) {
            ctx->pc = 0x13FE0Cu;
            goto label_13fe0c;
        }
    }
    ctx->pc = 0x13FDF4u;
    // 0x13fdf4: 0x0  nop
    ctx->pc = 0x13fdf4u;
    // NOP
label_13fdf8:
    // 0x13fdf8: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13FDF8u;
    {
        const bool branch_taken_0x13fdf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fdf8) {
            ctx->pc = 0x13FDFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FDF8u;
            // 0x13fdfc: 0x8e020028  lw          $v0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE14u;
            goto label_13fe14;
        }
    }
    ctx->pc = 0x13FE00u;
    // 0x13fe00: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fe00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fe04: 0x40f809  jalr        $v0
    ctx->pc = 0x13FE04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FE0Cu);
        ctx->pc = 0x13FE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE04u;
            // 0x13fe08: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FE0Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FE0Cu; }
            if (ctx->pc != 0x13FE0Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13FE0Cu;
label_13fe0c:
    // 0x13fe0c: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fe0cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe10: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x13fe10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
label_13fe14:
    // 0x13fe14: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x13fe14u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x13fe18: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x13FE18u;
    {
        const bool branch_taken_0x13fe18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FE1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE18u;
            // 0x13fe1c: 0xae020028  sw          $v0, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fe18) {
            ctx->pc = 0x13FEC0u;
            goto label_13fec0;
        }
    }
    ctx->pc = 0x13FE20u;
label_13fe20:
    // 0x13fe20: 0x56420021  bnel        $s2, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13FE20u;
    {
        const bool branch_taken_0x13fe20 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13fe20) {
            ctx->pc = 0x13FE24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE20u;
            // 0x13fe24: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FEA8u;
            goto label_13fea8;
        }
    }
    ctx->pc = 0x13FE28u;
    // 0x13fe28: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13fe28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13fe2c: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x13fe2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13fe30: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13FE30u;
    {
        const bool branch_taken_0x13fe30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fe30) {
            ctx->pc = 0x13FE34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE30u;
            // 0x13fe34: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE38u;
            goto label_13fe38;
        }
    }
    ctx->pc = 0x13FE38u;
label_13fe38:
    // 0x13fe38: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13fe38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13fe3c: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x13fe3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13fe40: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x13fe40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13fe44: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fe44u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe48: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x13fe48u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x13fe4c: 0x872023  subu        $a0, $a0, $a3
    ctx->pc = 0x13fe4cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x13fe50: 0x70a2001a  div1        $zero, $a1, $v0
    ctx->pc = 0x13fe50u;
    { int32_t divisor = GPR_S32(ctx, 2); int32_t dividend = GPR_S32(ctx, 5); if (divisor != 0) {     if (divisor == -1 && dividend == INT32_MIN) {         ctx->lo1 = (uint64_t)(int64_t)INT32_MIN; ctx->hi1 = 0;     } else {         ctx->lo1 = (uint64_t)(int64_t)(dividend / divisor);         ctx->hi1 = (uint64_t)(int64_t)(dividend % divisor);     } } else {     ctx->lo1 = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi1 = (uint64_t)(int64_t)dividend; } }
    // 0x13fe54: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x13fe54u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13fe58: 0x70001810  mfhi1       $v1
    ctx->pc = 0x13fe58u;
    SET_GPR_U64(ctx, 3, ctx->hi1);
    // 0x13fe5c: 0x2010  mfhi        $a0
    ctx->pc = 0x13fe5cu;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x13fe60: 0x54830007  bnel        $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x13FE60u;
    {
        const bool branch_taken_0x13fe60 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x13fe60) {
            ctx->pc = 0x13FE64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE60u;
            // 0x13fe64: 0x8e020038  lw          $v0, 0x38($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE80u;
            goto label_13fe80;
        }
    }
    ctx->pc = 0x13FE68u;
    // 0x13fe68: 0xae040018  sw          $a0, 0x18($s0)
    ctx->pc = 0x13fe68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 4));
    // 0x13fe6c: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x13fe6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13fe70: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13fe70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe74: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13fe74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13fe78: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13FE78u;
    {
        const bool branch_taken_0x13fe78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FE7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE78u;
            // 0x13fe7c: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fe78) {
            ctx->pc = 0x13FE94u;
            goto label_13fe94;
        }
    }
    ctx->pc = 0x13FE80u;
label_13fe80:
    // 0x13fe80: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13FE80u;
    {
        const bool branch_taken_0x13fe80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13fe80) {
            ctx->pc = 0x13FE84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE80u;
            // 0x13fe84: 0x8e020030  lw          $v0, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FE9Cu;
            goto label_13fe9c;
        }
    }
    ctx->pc = 0x13FE88u;
    // 0x13fe88: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13fe88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13fe8c: 0x40f809  jalr        $v0
    ctx->pc = 0x13FE8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FE94u);
        ctx->pc = 0x13FE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FE8Cu;
            // 0x13fe90: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FE94u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FE94u; }
            if (ctx->pc != 0x13FE94u) { return; }
        }
        }
    }
    ctx->pc = 0x13FE94u;
label_13fe94:
    // 0x13fe94: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x13fe94u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13fe98: 0x8e020030  lw          $v0, 0x30($s0)
    ctx->pc = 0x13fe98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
label_13fe9c:
    // 0x13fe9c: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x13fe9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x13fea0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FEA0u;
    {
        const bool branch_taken_0x13fea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEA0u;
            // 0x13fea4: 0xae020030  sw          $v0, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13fea0) {
            ctx->pc = 0x13FEC0u;
            goto label_13fec0;
        }
    }
    ctx->pc = 0x13FEA8u;
label_13fea8:
    // 0x13fea8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13fea8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13feac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FEACu;
    {
        const bool branch_taken_0x13feac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FEB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEACu;
            // 0x13feb0: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13feac) {
            ctx->pc = 0x13FEC0u;
            goto label_13fec0;
        }
    }
    ctx->pc = 0x13FEB4u;
    // 0x13feb4: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x13feb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x13feb8: 0x40f809  jalr        $v0
    ctx->pc = 0x13FEB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FEC0u);
        ctx->pc = 0x13FEBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEB8u;
            // 0x13febc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FEC0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FEC0u; }
            if (ctx->pc != 0x13FEC0u) { return; }
        }
        }
    }
    ctx->pc = 0x13FEC0u;
label_13fec0:
    // 0x13fec0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fec0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13fec4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fec4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fecc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13feccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fed0: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13FED0u;
    ctx->pc = 0x13FED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FED0u;
            // 0x13fed4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13FED8u;
label_13fed8:
    // 0x13fed8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13fed8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13fedc:
    // 0x13fedc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13fedcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13fee0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13fee0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13fee4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13fee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13fee8: 0x3e00008  jr          $ra
    ctx->pc = 0x13FEE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FEE8u;
            // 0x13feec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FEF0u;
    // 0x13fef0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13fef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13fef4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fef8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x13fef8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fefc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fefcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13ff00: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13ff00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ff04: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13ff04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13ff08: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13ff08u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ff0c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13ff0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13ff10: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13ff10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13ff14: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FF14u;
    SET_GPR_U32(ctx, 31, 0x13FF1Cu);
    ctx->pc = 0x13FF18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF14u;
            // 0x13ff18: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF1Cu; }
        if (ctx->pc != 0x13FF1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF1Cu; }
        if (ctx->pc != 0x13FF1Cu) { return; }
    }
    ctx->pc = 0x13FF1Cu;
label_13ff1c:
    // 0x13ff1c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13FF1Cu;
    {
        const bool branch_taken_0x13ff1c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13FF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF1Cu;
            // 0x13ff20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff1c) {
            ctx->pc = 0x13FF40u;
            goto label_13ff40;
        }
    }
    ctx->pc = 0x13FF24u;
    // 0x13ff24: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x13ff24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13ff28: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x13ff28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13ff2c: 0x8e250024  lw          $a1, 0x24($s1)
    ctx->pc = 0x13ff2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ff30: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13ff30u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ff34: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x13FF34u;
    {
        const bool branch_taken_0x13ff34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FF38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF34u;
            // 0x13ff38: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff34) {
            ctx->pc = 0x13FF5Cu;
            goto label_13ff5c;
        }
    }
    ctx->pc = 0x13FF3Cu;
    // 0x13ff3c: 0x0  nop
    ctx->pc = 0x13ff3cu;
    // NOP
label_13ff40:
    // 0x13ff40: 0x5602000d  bnel        $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13FF40u;
    {
        const bool branch_taken_0x13ff40 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x13ff40) {
            ctx->pc = 0x13FF44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF40u;
            // 0x13ff44: 0x8e220038  lw          $v0, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FF78u;
            goto label_13ff78;
        }
    }
    ctx->pc = 0x13FF48u;
    // 0x13ff48: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x13ff48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x13ff4c: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x13ff4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13ff50: 0x8e250024  lw          $a1, 0x24($s1)
    ctx->pc = 0x13ff50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ff54: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13ff54u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ff58: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x13ff58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_13ff5c:
    // 0x13ff5c: 0x658021  addu        $s0, $v1, $a1
    ctx->pc = 0x13ff5cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x13ff60: 0x90102a  slt         $v0, $a0, $s0
    ctx->pc = 0x13ff60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x13ff64: 0x82800b  movn        $s0, $a0, $v0
    ctx->pc = 0x13ff64u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 4));
    // 0x13ff68: 0x212182a  slt         $v1, $s0, $s2
    ctx->pc = 0x13ff68u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13ff6c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FF6Cu;
    {
        const bool branch_taken_0x13ff6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF6Cu;
            // 0x13ff70: 0x243800a  movz        $s0, $s2, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff6c) {
            ctx->pc = 0x13FF8Cu;
            goto label_13ff8c;
        }
    }
    ctx->pc = 0x13FF74u;
    // 0x13ff74: 0x0  nop
    ctx->pc = 0x13ff74u;
    // NOP
label_13ff78:
    // 0x13ff78: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FF78u;
    {
        const bool branch_taken_0x13ff78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF78u;
            // 0x13ff7c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff78) {
            ctx->pc = 0x13FF8Cu;
            goto label_13ff8c;
        }
    }
    ctx->pc = 0x13FF80u;
    // 0x13ff80: 0x8e24003c  lw          $a0, 0x3C($s1)
    ctx->pc = 0x13ff80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x13ff84: 0x40f809  jalr        $v0
    ctx->pc = 0x13FF84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FF8Cu);
        ctx->pc = 0x13FF88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF84u;
            // 0x13ff88: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FF8Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FF8Cu; }
            if (ctx->pc != 0x13FF8Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13FF8Cu;
label_13ff8c:
    // 0x13ff8c: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x13FF8Cu;
    SET_GPR_U32(ctx, 31, 0x13FF94u);
    ctx->pc = 0x13FF90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF8Cu;
            // 0x13ff90: 0xae700000  sw          $s0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF94u; }
        if (ctx->pc != 0x13FF94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF94u; }
        if (ctx->pc != 0x13FF94u) { return; }
    }
    ctx->pc = 0x13FF94u;
label_13ff94:
    // 0x13ff94: 0x2121026  xor         $v0, $s0, $s2
    ctx->pc = 0x13ff94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 18));
    // 0x13ff98: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ff98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ff9c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x13ff9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x13ffa0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ffa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ffa4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ffa4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ffa8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13ffa8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ffac: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13ffacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ffb0: 0x3e00008  jr          $ra
    ctx->pc = 0x13FFB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FFB0u;
            // 0x13ffb4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FA04u: goto label_13fa04;
            case 0x13FA50u: goto label_13fa50;
            case 0x13FA60u: goto label_13fa60;
            case 0x13FA74u: goto label_13fa74;
            case 0x13FA78u: goto label_13fa78;
            case 0x13FAB4u: goto label_13fab4;
            case 0x13FB0Cu: goto label_13fb0c;
            case 0x13FB38u: goto label_13fb38;
            case 0x13FB90u: goto label_13fb90;
            case 0x13FBC0u: goto label_13fbc0;
            case 0x13FBD8u: goto label_13fbd8;
            case 0x13FC34u: goto label_13fc34;
            case 0x13FC88u: goto label_13fc88;
            case 0x13FC90u: goto label_13fc90;
            case 0x13FCC8u: goto label_13fcc8;
            case 0x13FCD0u: goto label_13fcd0;
            case 0x13FCE0u: goto label_13fce0;
            case 0x13FD10u: goto label_13fd10;
            case 0x13FD28u: goto label_13fd28;
            case 0x13FD40u: goto label_13fd40;
            case 0x13FD44u: goto label_13fd44;
            case 0x13FD94u: goto label_13fd94;
            case 0x13FDB0u: goto label_13fdb0;
            case 0x13FDF8u: goto label_13fdf8;
            case 0x13FE0Cu: goto label_13fe0c;
            case 0x13FE14u: goto label_13fe14;
            case 0x13FE20u: goto label_13fe20;
            case 0x13FE38u: goto label_13fe38;
            case 0x13FE80u: goto label_13fe80;
            case 0x13FE94u: goto label_13fe94;
            case 0x13FE9Cu: goto label_13fe9c;
            case 0x13FEA8u: goto label_13fea8;
            case 0x13FEC0u: goto label_13fec0;
            case 0x13FED8u: goto label_13fed8;
            case 0x13FEDCu: goto label_13fedc;
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FFB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

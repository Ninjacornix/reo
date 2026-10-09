#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181888
// Address: 0x181888 - 0x181970
void sub_00181888_0x181888(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181888_0x181888");
#endif

    switch (ctx->pc) {
        case 0x1818c8u: goto label_1818c8;
        case 0x1818f8u: goto label_1818f8;
        case 0x181914u: goto label_181914;
        case 0x18193cu: goto label_18193c;
        case 0x181948u: goto label_181948;
        case 0x181950u: goto label_181950;
        default: break;
    }

    ctx->pc = 0x181888u;

    // 0x181888: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x181888u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x18188c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x18188cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x181890: 0x8c67fa10  lw          $a3, -0x5F0($v1)
    ctx->pc = 0x181890u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x181894: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181894u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181898: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x18189c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x18189cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1818a0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1818a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1818a4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1818a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1818a8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1818a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1818ac: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1818acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1818b0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1818b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1818b4: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x1818b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x1818b8: 0x10e00026  beqz        $a3, . + 4 + (0x26 << 2)
    ctx->pc = 0x1818B8u;
    {
        const bool branch_taken_0x1818b8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1818BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1818B8u;
            // 0x1818bc: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1818b8) {
            ctx->pc = 0x181954u;
            goto label_181954;
        }
    }
    ctx->pc = 0x1818C0u;
    // 0x1818c0: 0xc061e90  jal         func_187A40
    ctx->pc = 0x1818C0u;
    SET_GPR_U32(ctx, 31, 0x1818C8u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1818C8u; }
        if (ctx->pc != 0x1818C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1818C8u; }
        if (ctx->pc != 0x1818C8u) { return; }
    }
    ctx->pc = 0x1818C8u;
label_1818c8:
    // 0x1818c8: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x1818c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x1818cc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1818CCu;
    {
        const bool branch_taken_0x1818cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1818D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1818CCu;
            // 0x1818d0: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1818cc) {
            ctx->pc = 0x1818E0u;
            goto label_1818e0;
        }
    }
    ctx->pc = 0x1818D4u;
    // 0x1818d4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1818d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1818d8: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1818D8u;
    {
        const bool branch_taken_0x1818d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1818DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1818D8u;
            // 0x1818dc: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1818d8) {
            ctx->pc = 0x181954u;
            goto label_181954;
        }
    }
    ctx->pc = 0x1818E0u;
label_1818e0:
    // 0x1818e0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1818e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1818e4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1818e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1818e8: 0x1460001a  bnez        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1818E8u;
    {
        const bool branch_taken_0x1818e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1818ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1818E8u;
            // 0x1818ec: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1818e8) {
            ctx->pc = 0x181954u;
            goto label_181954;
        }
    }
    ctx->pc = 0x1818F0u;
    // 0x1818f0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1818F0u;
    SET_GPR_U32(ctx, 31, 0x1818F8u);
    ctx->pc = 0x1818F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1818F0u;
            // 0x1818f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1818F8u; }
        if (ctx->pc != 0x1818F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1818F8u; }
        if (ctx->pc != 0x1818F8u) { return; }
    }
    ctx->pc = 0x1818F8u;
label_1818f8:
    // 0x1818f8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1818f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1818fc: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x1818fcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181900: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181900u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181904: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x181904u;
    {
        const bool branch_taken_0x181904 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x181908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181904u;
            // 0x181908: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181904) {
            ctx->pc = 0x181954u;
            goto label_181954;
        }
    }
    ctx->pc = 0x18190Cu;
    // 0x18190c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18190Cu;
    SET_GPR_U32(ctx, 31, 0x181914u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181914u; }
        if (ctx->pc != 0x181914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181914u; }
        if (ctx->pc != 0x181914u) { return; }
    }
    ctx->pc = 0x181914u;
label_181914:
    // 0x181914: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x181914u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181918: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x181918u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x18191c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18191cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181920: 0x3442005b  ori         $v0, $v0, 0x5B
    ctx->pc = 0x181920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
    // 0x181924: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x181924u;
    {
        const bool branch_taken_0x181924 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x181928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181924u;
            // 0x181928: 0x2604041c  addiu       $a0, $s0, 0x41C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181924) {
            ctx->pc = 0x181954u;
            goto label_181954;
        }
    }
    ctx->pc = 0x18192Cu;
    // 0x18192c: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x18192cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x181930: 0xae130000  sw          $s3, 0x0($s0)
    ctx->pc = 0x181930u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 19));
    // 0x181934: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181934u;
    SET_GPR_U32(ctx, 31, 0x18193Cu);
    ctx->pc = 0x181938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181934u;
            // 0x181938: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18193Cu; }
        if (ctx->pc != 0x18193Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18193Cu; }
        if (ctx->pc != 0x18193Cu) { return; }
    }
    ctx->pc = 0x18193Cu;
label_18193c:
    // 0x18193c: 0x2604049c  addiu       $a0, $s0, 0x49C
    ctx->pc = 0x18193cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1180));
    // 0x181940: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181940u;
    SET_GPR_U32(ctx, 31, 0x181948u);
    ctx->pc = 0x181944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181940u;
            // 0x181944: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181948u; }
        if (ctx->pc != 0x181948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181948u; }
        if (ctx->pc != 0x181948u) { return; }
    }
    ctx->pc = 0x181948u;
label_181948:
    // 0x181948: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181948u;
    SET_GPR_U32(ctx, 31, 0x181950u);
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181950u; }
        if (ctx->pc != 0x181950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181950u; }
        if (ctx->pc != 0x181950u) { return; }
    }
    ctx->pc = 0x181950u;
label_181950:
    // 0x181950: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181950u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_181954:
    // 0x181954: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x181954u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181958: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x181958u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x18195c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x18195cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181960: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x181960u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x181964: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x181964u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x181968: 0x3e00008  jr          $ra
    ctx->pc = 0x181968u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18196Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181968u;
            // 0x18196c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1818C8u: goto label_1818c8;
            case 0x1818E0u: goto label_1818e0;
            case 0x1818F8u: goto label_1818f8;
            case 0x181914u: goto label_181914;
            case 0x18193Cu: goto label_18193c;
            case 0x181948u: goto label_181948;
            case 0x181950u: goto label_181950;
            case 0x181954u: goto label_181954;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181970u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

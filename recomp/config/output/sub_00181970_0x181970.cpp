#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181970
// Address: 0x181970 - 0x181d28
void sub_00181970_0x181970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181970_0x181970");
#endif

    switch (ctx->pc) {
        case 0x1819a8u: goto label_1819a8;
        case 0x1819d8u: goto label_1819d8;
        case 0x181a00u: goto label_181a00;
        case 0x181a08u: goto label_181a08;
        case 0x181a68u: goto label_181a68;
        case 0x181a70u: goto label_181a70;
        case 0x181ab0u: goto label_181ab0;
        case 0x181ad4u: goto label_181ad4;
        case 0x181afcu: goto label_181afc;
        case 0x181b14u: goto label_181b14;
        case 0x181b34u: goto label_181b34;
        case 0x181b50u: goto label_181b50;
        case 0x181b6cu: goto label_181b6c;
        case 0x181b8cu: goto label_181b8c;
        case 0x181bb8u: goto label_181bb8;
        case 0x181bd4u: goto label_181bd4;
        case 0x181bf4u: goto label_181bf4;
        case 0x181c0cu: goto label_181c0c;
        case 0x181c34u: goto label_181c34;
        case 0x181c80u: goto label_181c80;
        case 0x181cc8u: goto label_181cc8;
        case 0x181cecu: goto label_181cec;
        case 0x181d10u: goto label_181d10;
        case 0x181d20u: goto label_181d20;
        default: break;
    }

    ctx->pc = 0x181970u;

label_181970:
    // 0x181970: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x181970u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
label_181974:
    // 0x181974: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181974u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_181978:
    // 0x181978: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x181978u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
label_18197c:
    // 0x18197c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18197cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
label_181980:
    // 0x181980: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_181984:
    // 0x181984: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x181984u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_181988:
    // 0x181988: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x181988u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_18198c:
    // 0x18198c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x18198cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_181990:
    // 0x181990: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x181990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_181994:
    // 0x181994: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x181994u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
label_181998:
    // 0x181998: 0x10c0001c  beqz        $a2, . + 4 + (0x1C << 2)
label_18199c:
    if (ctx->pc == 0x18199Cu) {
        ctx->pc = 0x18199Cu;
            // 0x18199c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->pc = 0x1819A0u;
        goto label_1819a0;
    }
    ctx->pc = 0x181998u;
    {
        const bool branch_taken_0x181998 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x18199Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181998u;
            // 0x18199c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181998) {
            ctx->pc = 0x181A0Cu;
            goto label_181a0c;
        }
    }
    ctx->pc = 0x1819A0u;
label_1819a0:
    // 0x1819a0: 0xc061e90  jal         func_187A40
label_1819a4:
    if (ctx->pc == 0x1819A4u) {
        ctx->pc = 0x1819A8u;
        goto label_1819a8;
    }
    ctx->pc = 0x1819A0u;
    SET_GPR_U32(ctx, 31, 0x1819A8u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1819A8u; }
        if (ctx->pc != 0x1819A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1819A8u; }
        if (ctx->pc != 0x1819A8u) { return; }
    }
    ctx->pc = 0x1819A8u;
label_1819a8:
    // 0x1819a8: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x1819a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
label_1819ac:
    // 0x1819ac: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
label_1819b0:
    if (ctx->pc == 0x1819B0u) {
        ctx->pc = 0x1819B0u;
            // 0x1819b0: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->pc = 0x1819B4u;
        goto label_1819b4;
    }
    ctx->pc = 0x1819ACu;
    {
        const bool branch_taken_0x1819ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1819B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1819ACu;
            // 0x1819b0: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1819ac) {
            ctx->pc = 0x1819C0u;
            goto label_1819c0;
        }
    }
    ctx->pc = 0x1819B4u;
label_1819b4:
    // 0x1819b4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1819b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
label_1819b8:
    // 0x1819b8: 0x10000014  b           . + 4 + (0x14 << 2)
label_1819bc:
    if (ctx->pc == 0x1819BCu) {
        ctx->pc = 0x1819BCu;
            // 0x1819bc: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->pc = 0x1819C0u;
        goto label_1819c0;
    }
    ctx->pc = 0x1819B8u;
    {
        const bool branch_taken_0x1819b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1819BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1819B8u;
            // 0x1819bc: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1819b8) {
            ctx->pc = 0x181A0Cu;
            goto label_181a0c;
        }
    }
    ctx->pc = 0x1819C0u;
label_1819c0:
    // 0x1819c0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1819c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1819c4:
    // 0x1819c4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1819c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
label_1819c8:
    // 0x1819c8: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
label_1819cc:
    if (ctx->pc == 0x1819CCu) {
        ctx->pc = 0x1819CCu;
            // 0x1819cc: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->pc = 0x1819D0u;
        goto label_1819d0;
    }
    ctx->pc = 0x1819C8u;
    {
        const bool branch_taken_0x1819c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1819CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1819C8u;
            // 0x1819cc: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1819c8) {
            ctx->pc = 0x181A0Cu;
            goto label_181a0c;
        }
    }
    ctx->pc = 0x1819D0u;
label_1819d0:
    // 0x1819d0: 0xc042c56  jal         func_10B158
label_1819d4:
    if (ctx->pc == 0x1819D4u) {
        ctx->pc = 0x1819D4u;
            // 0x1819d4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1819D8u;
        goto label_1819d8;
    }
    ctx->pc = 0x1819D0u;
    SET_GPR_U32(ctx, 31, 0x1819D8u);
    ctx->pc = 0x1819D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1819D0u;
            // 0x1819d4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1819D8u; }
        if (ctx->pc != 0x1819D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1819D8u; }
        if (ctx->pc != 0x1819D8u) { return; }
    }
    ctx->pc = 0x1819D8u;
label_1819d8:
    // 0x1819d8: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x1819d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_1819dc:
    // 0x1819dc: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x1819dcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
label_1819e0:
    // 0x1819e0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1819e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
label_1819e4:
    // 0x1819e4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1819e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1819e8:
    // 0x1819e8: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
label_1819ec:
    if (ctx->pc == 0x1819ECu) {
        ctx->pc = 0x1819ECu;
            // 0x1819ec: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->pc = 0x1819F0u;
        goto label_1819f0;
    }
    ctx->pc = 0x1819E8u;
    {
        const bool branch_taken_0x1819e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1819ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1819E8u;
            // 0x1819ec: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1819e8) {
            ctx->pc = 0x181A0Cu;
            goto label_181a0c;
        }
    }
    ctx->pc = 0x1819F0u;
label_1819f0:
    // 0x1819f0: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x1819f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_1819f4:
    // 0x1819f4: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x1819f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
label_1819f8:
    // 0x1819f8: 0xc042bf0  jal         func_10AFC0
label_1819fc:
    if (ctx->pc == 0x1819FCu) {
        ctx->pc = 0x1819FCu;
            // 0x1819fc: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->pc = 0x181A00u;
        goto label_181a00;
    }
    ctx->pc = 0x1819F8u;
    SET_GPR_U32(ctx, 31, 0x181A00u);
    ctx->pc = 0x1819FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1819F8u;
            // 0x1819fc: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181A00u; }
        if (ctx->pc != 0x181A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181A00u; }
        if (ctx->pc != 0x181A00u) { return; }
    }
    ctx->pc = 0x181A00u;
label_181a00:
    // 0x181a00: 0xc062228  jal         func_1888A0
label_181a04:
    if (ctx->pc == 0x181A04u) {
        ctx->pc = 0x181A08u;
        goto label_181a08;
    }
    ctx->pc = 0x181A00u;
    SET_GPR_U32(ctx, 31, 0x181A08u);
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181A08u; }
        if (ctx->pc != 0x181A08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181A08u; }
        if (ctx->pc != 0x181A08u) { return; }
    }
    ctx->pc = 0x181A08u;
label_181a08:
    // 0x181a08: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181a08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_181a0c:
    // 0x181a0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x181a0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_181a10:
    // 0x181a10: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x181a10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_181a14:
    // 0x181a14: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x181a14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_181a18:
    // 0x181a18: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x181a18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_181a1c:
    // 0x181a1c: 0x3e00008  jr          $ra
label_181a20:
    if (ctx->pc == 0x181A20u) {
        ctx->pc = 0x181A20u;
            // 0x181a20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x181A24u;
        goto label_181a24;
    }
    ctx->pc = 0x181A1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181A1Cu;
            // 0x181a20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181970u: goto label_181970;
            case 0x181974u: goto label_181974;
            case 0x181978u: goto label_181978;
            case 0x18197Cu: goto label_18197c;
            case 0x181980u: goto label_181980;
            case 0x181984u: goto label_181984;
            case 0x181988u: goto label_181988;
            case 0x18198Cu: goto label_18198c;
            case 0x181990u: goto label_181990;
            case 0x181994u: goto label_181994;
            case 0x181998u: goto label_181998;
            case 0x18199Cu: goto label_18199c;
            case 0x1819A0u: goto label_1819a0;
            case 0x1819A4u: goto label_1819a4;
            case 0x1819A8u: goto label_1819a8;
            case 0x1819ACu: goto label_1819ac;
            case 0x1819B0u: goto label_1819b0;
            case 0x1819B4u: goto label_1819b4;
            case 0x1819B8u: goto label_1819b8;
            case 0x1819BCu: goto label_1819bc;
            case 0x1819C0u: goto label_1819c0;
            case 0x1819C4u: goto label_1819c4;
            case 0x1819C8u: goto label_1819c8;
            case 0x1819CCu: goto label_1819cc;
            case 0x1819D0u: goto label_1819d0;
            case 0x1819D4u: goto label_1819d4;
            case 0x1819D8u: goto label_1819d8;
            case 0x1819DCu: goto label_1819dc;
            case 0x1819E0u: goto label_1819e0;
            case 0x1819E4u: goto label_1819e4;
            case 0x1819E8u: goto label_1819e8;
            case 0x1819ECu: goto label_1819ec;
            case 0x1819F0u: goto label_1819f0;
            case 0x1819F4u: goto label_1819f4;
            case 0x1819F8u: goto label_1819f8;
            case 0x1819FCu: goto label_1819fc;
            case 0x181A00u: goto label_181a00;
            case 0x181A04u: goto label_181a04;
            case 0x181A08u: goto label_181a08;
            case 0x181A0Cu: goto label_181a0c;
            case 0x181A10u: goto label_181a10;
            case 0x181A14u: goto label_181a14;
            case 0x181A18u: goto label_181a18;
            case 0x181A1Cu: goto label_181a1c;
            case 0x181A20u: goto label_181a20;
            case 0x181A24u: goto label_181a24;
            case 0x181A28u: goto label_181a28;
            case 0x181A2Cu: goto label_181a2c;
            case 0x181A30u: goto label_181a30;
            case 0x181A34u: goto label_181a34;
            case 0x181A38u: goto label_181a38;
            case 0x181A3Cu: goto label_181a3c;
            case 0x181A40u: goto label_181a40;
            case 0x181A44u: goto label_181a44;
            case 0x181A48u: goto label_181a48;
            case 0x181A4Cu: goto label_181a4c;
            case 0x181A50u: goto label_181a50;
            case 0x181A54u: goto label_181a54;
            case 0x181A58u: goto label_181a58;
            case 0x181A5Cu: goto label_181a5c;
            case 0x181A60u: goto label_181a60;
            case 0x181A64u: goto label_181a64;
            case 0x181A68u: goto label_181a68;
            case 0x181A6Cu: goto label_181a6c;
            case 0x181A70u: goto label_181a70;
            case 0x181A74u: goto label_181a74;
            case 0x181A78u: goto label_181a78;
            case 0x181A7Cu: goto label_181a7c;
            case 0x181A80u: goto label_181a80;
            case 0x181A84u: goto label_181a84;
            case 0x181A88u: goto label_181a88;
            case 0x181A8Cu: goto label_181a8c;
            case 0x181A90u: goto label_181a90;
            case 0x181A94u: goto label_181a94;
            case 0x181A98u: goto label_181a98;
            case 0x181A9Cu: goto label_181a9c;
            case 0x181AA0u: goto label_181aa0;
            case 0x181AA4u: goto label_181aa4;
            case 0x181AA8u: goto label_181aa8;
            case 0x181AACu: goto label_181aac;
            case 0x181AB0u: goto label_181ab0;
            case 0x181AB4u: goto label_181ab4;
            case 0x181AB8u: goto label_181ab8;
            case 0x181ABCu: goto label_181abc;
            case 0x181AC0u: goto label_181ac0;
            case 0x181AC4u: goto label_181ac4;
            case 0x181AC8u: goto label_181ac8;
            case 0x181ACCu: goto label_181acc;
            case 0x181AD0u: goto label_181ad0;
            case 0x181AD4u: goto label_181ad4;
            case 0x181AD8u: goto label_181ad8;
            case 0x181ADCu: goto label_181adc;
            case 0x181AE0u: goto label_181ae0;
            case 0x181AE4u: goto label_181ae4;
            case 0x181AE8u: goto label_181ae8;
            case 0x181AECu: goto label_181aec;
            case 0x181AF0u: goto label_181af0;
            case 0x181AF4u: goto label_181af4;
            case 0x181AF8u: goto label_181af8;
            case 0x181AFCu: goto label_181afc;
            case 0x181B00u: goto label_181b00;
            case 0x181B04u: goto label_181b04;
            case 0x181B08u: goto label_181b08;
            case 0x181B0Cu: goto label_181b0c;
            case 0x181B10u: goto label_181b10;
            case 0x181B14u: goto label_181b14;
            case 0x181B18u: goto label_181b18;
            case 0x181B1Cu: goto label_181b1c;
            case 0x181B20u: goto label_181b20;
            case 0x181B24u: goto label_181b24;
            case 0x181B28u: goto label_181b28;
            case 0x181B2Cu: goto label_181b2c;
            case 0x181B30u: goto label_181b30;
            case 0x181B34u: goto label_181b34;
            case 0x181B38u: goto label_181b38;
            case 0x181B3Cu: goto label_181b3c;
            case 0x181B40u: goto label_181b40;
            case 0x181B44u: goto label_181b44;
            case 0x181B48u: goto label_181b48;
            case 0x181B4Cu: goto label_181b4c;
            case 0x181B50u: goto label_181b50;
            case 0x181B54u: goto label_181b54;
            case 0x181B58u: goto label_181b58;
            case 0x181B5Cu: goto label_181b5c;
            case 0x181B60u: goto label_181b60;
            case 0x181B64u: goto label_181b64;
            case 0x181B68u: goto label_181b68;
            case 0x181B6Cu: goto label_181b6c;
            case 0x181B70u: goto label_181b70;
            case 0x181B74u: goto label_181b74;
            case 0x181B78u: goto label_181b78;
            case 0x181B7Cu: goto label_181b7c;
            case 0x181B80u: goto label_181b80;
            case 0x181B84u: goto label_181b84;
            case 0x181B88u: goto label_181b88;
            case 0x181B8Cu: goto label_181b8c;
            case 0x181B90u: goto label_181b90;
            case 0x181B94u: goto label_181b94;
            case 0x181B98u: goto label_181b98;
            case 0x181B9Cu: goto label_181b9c;
            case 0x181BA0u: goto label_181ba0;
            case 0x181BA4u: goto label_181ba4;
            case 0x181BA8u: goto label_181ba8;
            case 0x181BACu: goto label_181bac;
            case 0x181BB0u: goto label_181bb0;
            case 0x181BB4u: goto label_181bb4;
            case 0x181BB8u: goto label_181bb8;
            case 0x181BBCu: goto label_181bbc;
            case 0x181BC0u: goto label_181bc0;
            case 0x181BC4u: goto label_181bc4;
            case 0x181BC8u: goto label_181bc8;
            case 0x181BCCu: goto label_181bcc;
            case 0x181BD0u: goto label_181bd0;
            case 0x181BD4u: goto label_181bd4;
            case 0x181BD8u: goto label_181bd8;
            case 0x181BDCu: goto label_181bdc;
            case 0x181BE0u: goto label_181be0;
            case 0x181BE4u: goto label_181be4;
            case 0x181BE8u: goto label_181be8;
            case 0x181BECu: goto label_181bec;
            case 0x181BF0u: goto label_181bf0;
            case 0x181BF4u: goto label_181bf4;
            case 0x181BF8u: goto label_181bf8;
            case 0x181BFCu: goto label_181bfc;
            case 0x181C00u: goto label_181c00;
            case 0x181C04u: goto label_181c04;
            case 0x181C08u: goto label_181c08;
            case 0x181C0Cu: goto label_181c0c;
            case 0x181C10u: goto label_181c10;
            case 0x181C14u: goto label_181c14;
            case 0x181C18u: goto label_181c18;
            case 0x181C1Cu: goto label_181c1c;
            case 0x181C20u: goto label_181c20;
            case 0x181C24u: goto label_181c24;
            case 0x181C28u: goto label_181c28;
            case 0x181C2Cu: goto label_181c2c;
            case 0x181C30u: goto label_181c30;
            case 0x181C34u: goto label_181c34;
            case 0x181C38u: goto label_181c38;
            case 0x181C3Cu: goto label_181c3c;
            case 0x181C40u: goto label_181c40;
            case 0x181C44u: goto label_181c44;
            case 0x181C48u: goto label_181c48;
            case 0x181C4Cu: goto label_181c4c;
            case 0x181C50u: goto label_181c50;
            case 0x181C54u: goto label_181c54;
            case 0x181C58u: goto label_181c58;
            case 0x181C5Cu: goto label_181c5c;
            case 0x181C60u: goto label_181c60;
            case 0x181C64u: goto label_181c64;
            case 0x181C68u: goto label_181c68;
            case 0x181C6Cu: goto label_181c6c;
            case 0x181C70u: goto label_181c70;
            case 0x181C74u: goto label_181c74;
            case 0x181C78u: goto label_181c78;
            case 0x181C7Cu: goto label_181c7c;
            case 0x181C80u: goto label_181c80;
            case 0x181C84u: goto label_181c84;
            case 0x181C88u: goto label_181c88;
            case 0x181C8Cu: goto label_181c8c;
            case 0x181C90u: goto label_181c90;
            case 0x181C94u: goto label_181c94;
            case 0x181C98u: goto label_181c98;
            case 0x181C9Cu: goto label_181c9c;
            case 0x181CA0u: goto label_181ca0;
            case 0x181CA4u: goto label_181ca4;
            case 0x181CA8u: goto label_181ca8;
            case 0x181CACu: goto label_181cac;
            case 0x181CB0u: goto label_181cb0;
            case 0x181CB4u: goto label_181cb4;
            case 0x181CB8u: goto label_181cb8;
            case 0x181CBCu: goto label_181cbc;
            case 0x181CC0u: goto label_181cc0;
            case 0x181CC4u: goto label_181cc4;
            case 0x181CC8u: goto label_181cc8;
            case 0x181CCCu: goto label_181ccc;
            case 0x181CD0u: goto label_181cd0;
            case 0x181CD4u: goto label_181cd4;
            case 0x181CD8u: goto label_181cd8;
            case 0x181CDCu: goto label_181cdc;
            case 0x181CE0u: goto label_181ce0;
            case 0x181CE4u: goto label_181ce4;
            case 0x181CE8u: goto label_181ce8;
            case 0x181CECu: goto label_181cec;
            case 0x181CF0u: goto label_181cf0;
            case 0x181CF4u: goto label_181cf4;
            case 0x181CF8u: goto label_181cf8;
            case 0x181CFCu: goto label_181cfc;
            case 0x181D00u: goto label_181d00;
            case 0x181D04u: goto label_181d04;
            case 0x181D08u: goto label_181d08;
            case 0x181D0Cu: goto label_181d0c;
            case 0x181D10u: goto label_181d10;
            case 0x181D14u: goto label_181d14;
            case 0x181D18u: goto label_181d18;
            case 0x181D1Cu: goto label_181d1c;
            case 0x181D20u: goto label_181d20;
            case 0x181D24u: goto label_181d24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181A24u;
label_181a24:
    // 0x181a24: 0x0  nop
    ctx->pc = 0x181a24u;
    // NOP
label_181a28:
    // 0x181a28: 0x27bdfdc0  addiu       $sp, $sp, -0x240
    ctx->pc = 0x181a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966720));
label_181a2c:
    // 0x181a2c: 0xffb00200  sd          $s0, 0x200($sp)
    ctx->pc = 0x181a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 512), GPR_U64(ctx, 16));
label_181a30:
    // 0x181a30: 0xffbf0238  sd          $ra, 0x238($sp)
    ctx->pc = 0x181a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 568), GPR_U64(ctx, 31));
label_181a34:
    // 0x181a34: 0xffb10208  sd          $s1, 0x208($sp)
    ctx->pc = 0x181a34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 520), GPR_U64(ctx, 17));
label_181a38:
    // 0x181a38: 0x3c110028  lui         $s1, 0x28
    ctx->pc = 0x181a38u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)40 << 16));
label_181a3c:
    // 0x181a3c: 0xffb20210  sd          $s2, 0x210($sp)
    ctx->pc = 0x181a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 528), GPR_U64(ctx, 18));
label_181a40:
    // 0x181a40: 0x27b20018  addiu       $s2, $sp, 0x18
    ctx->pc = 0x181a40u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
label_181a44:
    // 0x181a44: 0xffb30218  sd          $s3, 0x218($sp)
    ctx->pc = 0x181a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 536), GPR_U64(ctx, 19));
label_181a48:
    // 0x181a48: 0x3c130028  lui         $s3, 0x28
    ctx->pc = 0x181a48u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)40 << 16));
label_181a4c:
    // 0x181a4c: 0xffb40220  sd          $s4, 0x220($sp)
    ctx->pc = 0x181a4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 544), GPR_U64(ctx, 20));
label_181a50:
    // 0x181a50: 0x27b40008  addiu       $s4, $sp, 0x8
    ctx->pc = 0x181a50u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
label_181a54:
    // 0x181a54: 0xffb50228  sd          $s5, 0x228($sp)
    ctx->pc = 0x181a54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 552), GPR_U64(ctx, 21));
label_181a58:
    // 0x181a58: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x181a58u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
label_181a5c:
    // 0x181a5c: 0xffb60230  sd          $s6, 0x230($sp)
    ctx->pc = 0x181a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 560), GPR_U64(ctx, 22));
label_181a60:
    // 0x181a60: 0x27b60040  addiu       $s6, $sp, 0x40
    ctx->pc = 0x181a60u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
label_181a64:
    // 0x181a64: 0x0  nop
    ctx->pc = 0x181a64u;
    // NOP
label_181a68:
    // 0x181a68: 0xc062220  jal         func_188880
label_181a6c:
    if (ctx->pc == 0x181A6Cu) {
        ctx->pc = 0x181A70u;
        goto label_181a70;
    }
    ctx->pc = 0x181A68u;
    SET_GPR_U32(ctx, 31, 0x181A70u);
    ctx->pc = 0x188880u;
    if (runtime->hasFunction(0x188880u)) {
        auto targetFn = runtime->lookupFunction(0x188880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181A70u; }
        if (ctx->pc != 0x181A70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188880_0x188880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181A70u; }
        if (ctx->pc != 0x181A70u) { return; }
    }
    ctx->pc = 0x181A70u;
label_181a70:
    // 0x181a70: 0x26239500  addiu       $v1, $s1, -0x6B00
    ctx->pc = 0x181a70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181a74:
    // 0x181a74: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x181a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
label_181a78:
    // 0x181a78: 0x2442fffe  addiu       $v0, $v0, -0x2
    ctx->pc = 0x181a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
label_181a7c:
    // 0x181a7c: 0x2c430063  sltiu       $v1, $v0, 0x63
    ctx->pc = 0x181a7cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)99) ? 1 : 0);
label_181a80:
    // 0x181a80: 0x506000a5  beql        $v1, $zero, . + 4 + (0xA5 << 2)
label_181a84:
    if (ctx->pc == 0x181A84u) {
        ctx->pc = 0x181A84u;
            // 0x181a84: 0x26629a20  addiu       $v0, $s3, -0x65E0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294941216));
        ctx->pc = 0x181A88u;
        goto label_181a88;
    }
    ctx->pc = 0x181A80u;
    {
        const bool branch_taken_0x181a80 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x181a80) {
            ctx->pc = 0x181A84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x181A80u;
            // 0x181a84: 0x26629a20  addiu       $v0, $s3, -0x65E0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294941216));
        ctx->in_delay_slot = false;
            ctx->pc = 0x181D18u;
            goto label_181d18;
        }
    }
    ctx->pc = 0x181A88u;
label_181a88:
    // 0x181a88: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x181a88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_181a8c:
    // 0x181a8c: 0x26a31620  addiu       $v1, $s5, 0x1620
    ctx->pc = 0x181a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 5664));
label_181a90:
    // 0x181a90: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x181a90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_181a94:
    // 0x181a94: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x181a94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_181a98:
    // 0x181a98: 0x800008  jr          $a0
label_181a9c:
    if (ctx->pc == 0x181A9Cu) {
        ctx->pc = 0x181AA0u;
        goto label_181aa0;
    }
    ctx->pc = 0x181A98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181970u: goto label_181970;
            case 0x181974u: goto label_181974;
            case 0x181978u: goto label_181978;
            case 0x18197Cu: goto label_18197c;
            case 0x181980u: goto label_181980;
            case 0x181984u: goto label_181984;
            case 0x181988u: goto label_181988;
            case 0x18198Cu: goto label_18198c;
            case 0x181990u: goto label_181990;
            case 0x181994u: goto label_181994;
            case 0x181998u: goto label_181998;
            case 0x18199Cu: goto label_18199c;
            case 0x1819A0u: goto label_1819a0;
            case 0x1819A4u: goto label_1819a4;
            case 0x1819A8u: goto label_1819a8;
            case 0x1819ACu: goto label_1819ac;
            case 0x1819B0u: goto label_1819b0;
            case 0x1819B4u: goto label_1819b4;
            case 0x1819B8u: goto label_1819b8;
            case 0x1819BCu: goto label_1819bc;
            case 0x1819C0u: goto label_1819c0;
            case 0x1819C4u: goto label_1819c4;
            case 0x1819C8u: goto label_1819c8;
            case 0x1819CCu: goto label_1819cc;
            case 0x1819D0u: goto label_1819d0;
            case 0x1819D4u: goto label_1819d4;
            case 0x1819D8u: goto label_1819d8;
            case 0x1819DCu: goto label_1819dc;
            case 0x1819E0u: goto label_1819e0;
            case 0x1819E4u: goto label_1819e4;
            case 0x1819E8u: goto label_1819e8;
            case 0x1819ECu: goto label_1819ec;
            case 0x1819F0u: goto label_1819f0;
            case 0x1819F4u: goto label_1819f4;
            case 0x1819F8u: goto label_1819f8;
            case 0x1819FCu: goto label_1819fc;
            case 0x181A00u: goto label_181a00;
            case 0x181A04u: goto label_181a04;
            case 0x181A08u: goto label_181a08;
            case 0x181A0Cu: goto label_181a0c;
            case 0x181A10u: goto label_181a10;
            case 0x181A14u: goto label_181a14;
            case 0x181A18u: goto label_181a18;
            case 0x181A1Cu: goto label_181a1c;
            case 0x181A20u: goto label_181a20;
            case 0x181A24u: goto label_181a24;
            case 0x181A28u: goto label_181a28;
            case 0x181A2Cu: goto label_181a2c;
            case 0x181A30u: goto label_181a30;
            case 0x181A34u: goto label_181a34;
            case 0x181A38u: goto label_181a38;
            case 0x181A3Cu: goto label_181a3c;
            case 0x181A40u: goto label_181a40;
            case 0x181A44u: goto label_181a44;
            case 0x181A48u: goto label_181a48;
            case 0x181A4Cu: goto label_181a4c;
            case 0x181A50u: goto label_181a50;
            case 0x181A54u: goto label_181a54;
            case 0x181A58u: goto label_181a58;
            case 0x181A5Cu: goto label_181a5c;
            case 0x181A60u: goto label_181a60;
            case 0x181A64u: goto label_181a64;
            case 0x181A68u: goto label_181a68;
            case 0x181A6Cu: goto label_181a6c;
            case 0x181A70u: goto label_181a70;
            case 0x181A74u: goto label_181a74;
            case 0x181A78u: goto label_181a78;
            case 0x181A7Cu: goto label_181a7c;
            case 0x181A80u: goto label_181a80;
            case 0x181A84u: goto label_181a84;
            case 0x181A88u: goto label_181a88;
            case 0x181A8Cu: goto label_181a8c;
            case 0x181A90u: goto label_181a90;
            case 0x181A94u: goto label_181a94;
            case 0x181A98u: goto label_181a98;
            case 0x181A9Cu: goto label_181a9c;
            case 0x181AA0u: goto label_181aa0;
            case 0x181AA4u: goto label_181aa4;
            case 0x181AA8u: goto label_181aa8;
            case 0x181AACu: goto label_181aac;
            case 0x181AB0u: goto label_181ab0;
            case 0x181AB4u: goto label_181ab4;
            case 0x181AB8u: goto label_181ab8;
            case 0x181ABCu: goto label_181abc;
            case 0x181AC0u: goto label_181ac0;
            case 0x181AC4u: goto label_181ac4;
            case 0x181AC8u: goto label_181ac8;
            case 0x181ACCu: goto label_181acc;
            case 0x181AD0u: goto label_181ad0;
            case 0x181AD4u: goto label_181ad4;
            case 0x181AD8u: goto label_181ad8;
            case 0x181ADCu: goto label_181adc;
            case 0x181AE0u: goto label_181ae0;
            case 0x181AE4u: goto label_181ae4;
            case 0x181AE8u: goto label_181ae8;
            case 0x181AECu: goto label_181aec;
            case 0x181AF0u: goto label_181af0;
            case 0x181AF4u: goto label_181af4;
            case 0x181AF8u: goto label_181af8;
            case 0x181AFCu: goto label_181afc;
            case 0x181B00u: goto label_181b00;
            case 0x181B04u: goto label_181b04;
            case 0x181B08u: goto label_181b08;
            case 0x181B0Cu: goto label_181b0c;
            case 0x181B10u: goto label_181b10;
            case 0x181B14u: goto label_181b14;
            case 0x181B18u: goto label_181b18;
            case 0x181B1Cu: goto label_181b1c;
            case 0x181B20u: goto label_181b20;
            case 0x181B24u: goto label_181b24;
            case 0x181B28u: goto label_181b28;
            case 0x181B2Cu: goto label_181b2c;
            case 0x181B30u: goto label_181b30;
            case 0x181B34u: goto label_181b34;
            case 0x181B38u: goto label_181b38;
            case 0x181B3Cu: goto label_181b3c;
            case 0x181B40u: goto label_181b40;
            case 0x181B44u: goto label_181b44;
            case 0x181B48u: goto label_181b48;
            case 0x181B4Cu: goto label_181b4c;
            case 0x181B50u: goto label_181b50;
            case 0x181B54u: goto label_181b54;
            case 0x181B58u: goto label_181b58;
            case 0x181B5Cu: goto label_181b5c;
            case 0x181B60u: goto label_181b60;
            case 0x181B64u: goto label_181b64;
            case 0x181B68u: goto label_181b68;
            case 0x181B6Cu: goto label_181b6c;
            case 0x181B70u: goto label_181b70;
            case 0x181B74u: goto label_181b74;
            case 0x181B78u: goto label_181b78;
            case 0x181B7Cu: goto label_181b7c;
            case 0x181B80u: goto label_181b80;
            case 0x181B84u: goto label_181b84;
            case 0x181B88u: goto label_181b88;
            case 0x181B8Cu: goto label_181b8c;
            case 0x181B90u: goto label_181b90;
            case 0x181B94u: goto label_181b94;
            case 0x181B98u: goto label_181b98;
            case 0x181B9Cu: goto label_181b9c;
            case 0x181BA0u: goto label_181ba0;
            case 0x181BA4u: goto label_181ba4;
            case 0x181BA8u: goto label_181ba8;
            case 0x181BACu: goto label_181bac;
            case 0x181BB0u: goto label_181bb0;
            case 0x181BB4u: goto label_181bb4;
            case 0x181BB8u: goto label_181bb8;
            case 0x181BBCu: goto label_181bbc;
            case 0x181BC0u: goto label_181bc0;
            case 0x181BC4u: goto label_181bc4;
            case 0x181BC8u: goto label_181bc8;
            case 0x181BCCu: goto label_181bcc;
            case 0x181BD0u: goto label_181bd0;
            case 0x181BD4u: goto label_181bd4;
            case 0x181BD8u: goto label_181bd8;
            case 0x181BDCu: goto label_181bdc;
            case 0x181BE0u: goto label_181be0;
            case 0x181BE4u: goto label_181be4;
            case 0x181BE8u: goto label_181be8;
            case 0x181BECu: goto label_181bec;
            case 0x181BF0u: goto label_181bf0;
            case 0x181BF4u: goto label_181bf4;
            case 0x181BF8u: goto label_181bf8;
            case 0x181BFCu: goto label_181bfc;
            case 0x181C00u: goto label_181c00;
            case 0x181C04u: goto label_181c04;
            case 0x181C08u: goto label_181c08;
            case 0x181C0Cu: goto label_181c0c;
            case 0x181C10u: goto label_181c10;
            case 0x181C14u: goto label_181c14;
            case 0x181C18u: goto label_181c18;
            case 0x181C1Cu: goto label_181c1c;
            case 0x181C20u: goto label_181c20;
            case 0x181C24u: goto label_181c24;
            case 0x181C28u: goto label_181c28;
            case 0x181C2Cu: goto label_181c2c;
            case 0x181C30u: goto label_181c30;
            case 0x181C34u: goto label_181c34;
            case 0x181C38u: goto label_181c38;
            case 0x181C3Cu: goto label_181c3c;
            case 0x181C40u: goto label_181c40;
            case 0x181C44u: goto label_181c44;
            case 0x181C48u: goto label_181c48;
            case 0x181C4Cu: goto label_181c4c;
            case 0x181C50u: goto label_181c50;
            case 0x181C54u: goto label_181c54;
            case 0x181C58u: goto label_181c58;
            case 0x181C5Cu: goto label_181c5c;
            case 0x181C60u: goto label_181c60;
            case 0x181C64u: goto label_181c64;
            case 0x181C68u: goto label_181c68;
            case 0x181C6Cu: goto label_181c6c;
            case 0x181C70u: goto label_181c70;
            case 0x181C74u: goto label_181c74;
            case 0x181C78u: goto label_181c78;
            case 0x181C7Cu: goto label_181c7c;
            case 0x181C80u: goto label_181c80;
            case 0x181C84u: goto label_181c84;
            case 0x181C88u: goto label_181c88;
            case 0x181C8Cu: goto label_181c8c;
            case 0x181C90u: goto label_181c90;
            case 0x181C94u: goto label_181c94;
            case 0x181C98u: goto label_181c98;
            case 0x181C9Cu: goto label_181c9c;
            case 0x181CA0u: goto label_181ca0;
            case 0x181CA4u: goto label_181ca4;
            case 0x181CA8u: goto label_181ca8;
            case 0x181CACu: goto label_181cac;
            case 0x181CB0u: goto label_181cb0;
            case 0x181CB4u: goto label_181cb4;
            case 0x181CB8u: goto label_181cb8;
            case 0x181CBCu: goto label_181cbc;
            case 0x181CC0u: goto label_181cc0;
            case 0x181CC4u: goto label_181cc4;
            case 0x181CC8u: goto label_181cc8;
            case 0x181CCCu: goto label_181ccc;
            case 0x181CD0u: goto label_181cd0;
            case 0x181CD4u: goto label_181cd4;
            case 0x181CD8u: goto label_181cd8;
            case 0x181CDCu: goto label_181cdc;
            case 0x181CE0u: goto label_181ce0;
            case 0x181CE4u: goto label_181ce4;
            case 0x181CE8u: goto label_181ce8;
            case 0x181CECu: goto label_181cec;
            case 0x181CF0u: goto label_181cf0;
            case 0x181CF4u: goto label_181cf4;
            case 0x181CF8u: goto label_181cf8;
            case 0x181CFCu: goto label_181cfc;
            case 0x181D00u: goto label_181d00;
            case 0x181D04u: goto label_181d04;
            case 0x181D08u: goto label_181d08;
            case 0x181D0Cu: goto label_181d0c;
            case 0x181D10u: goto label_181d10;
            case 0x181D14u: goto label_181d14;
            case 0x181D18u: goto label_181d18;
            case 0x181D1Cu: goto label_181d1c;
            case 0x181D20u: goto label_181d20;
            case 0x181D24u: goto label_181d24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181AA0u;
label_181aa0:
    // 0x181aa0: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181aa0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181aa4:
    // 0x181aa4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181aa4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181aa8:
    // 0x181aa8: 0xc060ca4  jal         func_183290
label_181aac:
    if (ctx->pc == 0x181AACu) {
        ctx->pc = 0x181AACu;
            // 0x181aac: 0x8e05000c  lw          $a1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->pc = 0x181AB0u;
        goto label_181ab0;
    }
    ctx->pc = 0x181AA8u;
    SET_GPR_U32(ctx, 31, 0x181AB0u);
    ctx->pc = 0x181AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181AA8u;
            // 0x181aac: 0x8e05000c  lw          $a1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183290u;
    if (runtime->hasFunction(0x183290u)) {
        auto targetFn = runtime->lookupFunction(0x183290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181AB0u; }
        if (ctx->pc != 0x181AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183290_0x183290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181AB0u; }
        if (ctx->pc != 0x181AB0u) { return; }
    }
    ctx->pc = 0x181AB0u;
label_181ab0:
    // 0x181ab0: 0x10000098  b           . + 4 + (0x98 << 2)
label_181ab4:
    if (ctx->pc == 0x181AB4u) {
        ctx->pc = 0x181AB4u;
            // 0x181ab4: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181AB8u;
        goto label_181ab8;
    }
    ctx->pc = 0x181AB0u;
    {
        const bool branch_taken_0x181ab0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181AB0u;
            // 0x181ab4: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181ab0) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181AB8u;
label_181ab8:
    // 0x181ab8: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181ab8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181abc:
    // 0x181abc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181abcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181ac0:
    // 0x181ac0: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181ac0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181ac4:
    // 0x181ac4: 0x8e06000c  lw          $a2, 0xC($s0)
    ctx->pc = 0x181ac4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_181ac8:
    // 0x181ac8: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x181ac8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_181acc:
    // 0x181acc: 0xc06120a  jal         func_184828
label_181ad0:
    if (ctx->pc == 0x181AD0u) {
        ctx->pc = 0x181AD0u;
            // 0x181ad0: 0x8e080014  lw          $t0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->pc = 0x181AD4u;
        goto label_181ad4;
    }
    ctx->pc = 0x181ACCu;
    SET_GPR_U32(ctx, 31, 0x181AD4u);
    ctx->pc = 0x181AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181ACCu;
            // 0x181ad0: 0x8e080014  lw          $t0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184828u;
    if (runtime->hasFunction(0x184828u)) {
        auto targetFn = runtime->lookupFunction(0x184828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181AD4u; }
        if (ctx->pc != 0x181AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184828_0x184828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181AD4u; }
        if (ctx->pc != 0x181AD4u) { return; }
    }
    ctx->pc = 0x181AD4u;
label_181ad4:
    // 0x181ad4: 0x1000008f  b           . + 4 + (0x8F << 2)
label_181ad8:
    if (ctx->pc == 0x181AD8u) {
        ctx->pc = 0x181AD8u;
            // 0x181ad8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181ADCu;
        goto label_181adc;
    }
    ctx->pc = 0x181AD4u;
    {
        const bool branch_taken_0x181ad4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181AD4u;
            // 0x181ad8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181ad4) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181ADCu;
label_181adc:
    // 0x181adc: 0x0  nop
    ctx->pc = 0x181adcu;
    // NOP
label_181ae0:
    // 0x181ae0: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181ae0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181ae4:
    // 0x181ae4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181ae8:
    // 0x181ae8: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181aec:
    // 0x181aec: 0x8e06000c  lw          $a2, 0xC($s0)
    ctx->pc = 0x181aecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_181af0:
    // 0x181af0: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x181af0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_181af4:
    // 0x181af4: 0xc061632  jal         func_1858C8
label_181af8:
    if (ctx->pc == 0x181AF8u) {
        ctx->pc = 0x181AF8u;
            // 0x181af8: 0x8e080014  lw          $t0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->pc = 0x181AFCu;
        goto label_181afc;
    }
    ctx->pc = 0x181AF4u;
    SET_GPR_U32(ctx, 31, 0x181AFCu);
    ctx->pc = 0x181AF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181AF4u;
            // 0x181af8: 0x8e080014  lw          $t0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1858C8u;
    if (runtime->hasFunction(0x1858C8u)) {
        auto targetFn = runtime->lookupFunction(0x1858C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181AFCu; }
        if (ctx->pc != 0x181AFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001858C8_0x1858c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181AFCu; }
        if (ctx->pc != 0x181AFCu) { return; }
    }
    ctx->pc = 0x181AFCu;
label_181afc:
    // 0x181afc: 0x10000085  b           . + 4 + (0x85 << 2)
label_181b00:
    if (ctx->pc == 0x181B00u) {
        ctx->pc = 0x181B00u;
            // 0x181b00: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181B04u;
        goto label_181b04;
    }
    ctx->pc = 0x181AFCu;
    {
        const bool branch_taken_0x181afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181AFCu;
            // 0x181b00: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181afc) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181B04u;
label_181b04:
    // 0x181b04: 0x0  nop
    ctx->pc = 0x181b04u;
    // NOP
label_181b08:
    // 0x181b08: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181b08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181b0c:
    // 0x181b0c: 0xc060d9c  jal         func_183670
label_181b10:
    if (ctx->pc == 0x181B10u) {
        ctx->pc = 0x181B10u;
            // 0x181b10: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->pc = 0x181B14u;
        goto label_181b14;
    }
    ctx->pc = 0x181B0Cu;
    SET_GPR_U32(ctx, 31, 0x181B14u);
    ctx->pc = 0x181B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181B0Cu;
            // 0x181b10: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183670u;
    if (runtime->hasFunction(0x183670u)) {
        auto targetFn = runtime->lookupFunction(0x183670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B14u; }
        if (ctx->pc != 0x181B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183670_0x183670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B14u; }
        if (ctx->pc != 0x181B14u) { return; }
    }
    ctx->pc = 0x181B14u;
label_181b14:
    // 0x181b14: 0x1000007f  b           . + 4 + (0x7F << 2)
label_181b18:
    if (ctx->pc == 0x181B18u) {
        ctx->pc = 0x181B18u;
            // 0x181b18: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181B1Cu;
        goto label_181b1c;
    }
    ctx->pc = 0x181B14u;
    {
        const bool branch_taken_0x181b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181B14u;
            // 0x181b18: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181b14) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181B1Cu;
label_181b1c:
    // 0x181b1c: 0x0  nop
    ctx->pc = 0x181b1cu;
    // NOP
label_181b20:
    // 0x181b20: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181b20u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181b24:
    // 0x181b24: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181b24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181b28:
    // 0x181b28: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181b28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181b2c:
    // 0x181b2c: 0xc0614a0  jal         func_185280
label_181b30:
    if (ctx->pc == 0x181B30u) {
        ctx->pc = 0x181B30u;
            // 0x181b30: 0x8e06000c  lw          $a2, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->pc = 0x181B34u;
        goto label_181b34;
    }
    ctx->pc = 0x181B2Cu;
    SET_GPR_U32(ctx, 31, 0x181B34u);
    ctx->pc = 0x181B30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181B2Cu;
            // 0x181b30: 0x8e06000c  lw          $a2, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x185280u;
    if (runtime->hasFunction(0x185280u)) {
        auto targetFn = runtime->lookupFunction(0x185280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B34u; }
        if (ctx->pc != 0x181B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00185280_0x185280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B34u; }
        if (ctx->pc != 0x181B34u) { return; }
    }
    ctx->pc = 0x181B34u;
label_181b34:
    // 0x181b34: 0x10000077  b           . + 4 + (0x77 << 2)
label_181b38:
    if (ctx->pc == 0x181B38u) {
        ctx->pc = 0x181B38u;
            // 0x181b38: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181B3Cu;
        goto label_181b3c;
    }
    ctx->pc = 0x181B34u;
    {
        const bool branch_taken_0x181b34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181B34u;
            // 0x181b38: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181b34) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181B3Cu;
label_181b3c:
    // 0x181b3c: 0x0  nop
    ctx->pc = 0x181b3cu;
    // NOP
label_181b40:
    // 0x181b40: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181b40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181b44:
    // 0x181b44: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181b44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181b48:
    // 0x181b48: 0xc061790  jal         func_185E40
label_181b4c:
    if (ctx->pc == 0x181B4Cu) {
        ctx->pc = 0x181B4Cu;
            // 0x181b4c: 0x2605041c  addiu       $a1, $s0, 0x41C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
        ctx->pc = 0x181B50u;
        goto label_181b50;
    }
    ctx->pc = 0x181B48u;
    SET_GPR_U32(ctx, 31, 0x181B50u);
    ctx->pc = 0x181B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181B48u;
            // 0x181b4c: 0x2605041c  addiu       $a1, $s0, 0x41C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
        ctx->in_delay_slot = false;
    ctx->pc = 0x185E40u;
    if (runtime->hasFunction(0x185E40u)) {
        auto targetFn = runtime->lookupFunction(0x185E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B50u; }
        if (ctx->pc != 0x181B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00185E40_0x185e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B50u; }
        if (ctx->pc != 0x181B50u) { return; }
    }
    ctx->pc = 0x181B50u;
label_181b50:
    // 0x181b50: 0x10000070  b           . + 4 + (0x70 << 2)
label_181b54:
    if (ctx->pc == 0x181B54u) {
        ctx->pc = 0x181B54u;
            // 0x181b54: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181B58u;
        goto label_181b58;
    }
    ctx->pc = 0x181B50u;
    {
        const bool branch_taken_0x181b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181B50u;
            // 0x181b54: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181b50) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181B58u;
label_181b58:
    // 0x181b58: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181b58u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181b5c:
    // 0x181b5c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181b5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181b60:
    // 0x181b60: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181b60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181b64:
    // 0x181b64: 0xc0614a0  jal         func_185280
label_181b68:
    if (ctx->pc == 0x181B68u) {
        ctx->pc = 0x181B68u;
            // 0x181b68: 0x8e06000c  lw          $a2, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->pc = 0x181B6Cu;
        goto label_181b6c;
    }
    ctx->pc = 0x181B64u;
    SET_GPR_U32(ctx, 31, 0x181B6Cu);
    ctx->pc = 0x181B68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181B64u;
            // 0x181b68: 0x8e06000c  lw          $a2, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x185280u;
    if (runtime->hasFunction(0x185280u)) {
        auto targetFn = runtime->lookupFunction(0x185280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B6Cu; }
        if (ctx->pc != 0x181B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00185280_0x185280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B6Cu; }
        if (ctx->pc != 0x181B6Cu) { return; }
    }
    ctx->pc = 0x181B6Cu;
label_181b6c:
    // 0x181b6c: 0x10000069  b           . + 4 + (0x69 << 2)
label_181b70:
    if (ctx->pc == 0x181B70u) {
        ctx->pc = 0x181B70u;
            // 0x181b70: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181B74u;
        goto label_181b74;
    }
    ctx->pc = 0x181B6Cu;
    {
        const bool branch_taken_0x181b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181B6Cu;
            // 0x181b70: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181b6c) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181B74u;
label_181b74:
    // 0x181b74: 0x0  nop
    ctx->pc = 0x181b74u;
    // NOP
label_181b78:
    // 0x181b78: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181b78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181b7c:
    // 0x181b7c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181b80:
    // 0x181b80: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181b80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181b84:
    // 0x181b84: 0xc06182c  jal         func_1860B0
label_181b88:
    if (ctx->pc == 0x181B88u) {
        ctx->pc = 0x181B88u;
            // 0x181b88: 0x8e06000c  lw          $a2, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->pc = 0x181B8Cu;
        goto label_181b8c;
    }
    ctx->pc = 0x181B84u;
    SET_GPR_U32(ctx, 31, 0x181B8Cu);
    ctx->pc = 0x181B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181B84u;
            // 0x181b88: 0x8e06000c  lw          $a2, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1860B0u;
    if (runtime->hasFunction(0x1860B0u)) {
        auto targetFn = runtime->lookupFunction(0x1860B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B8Cu; }
        if (ctx->pc != 0x181B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001860B0_0x1860b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181B8Cu; }
        if (ctx->pc != 0x181B8Cu) { return; }
    }
    ctx->pc = 0x181B8Cu;
label_181b8c:
    // 0x181b8c: 0x10000061  b           . + 4 + (0x61 << 2)
label_181b90:
    if (ctx->pc == 0x181B90u) {
        ctx->pc = 0x181B90u;
            // 0x181b90: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181B94u;
        goto label_181b94;
    }
    ctx->pc = 0x181B8Cu;
    {
        const bool branch_taken_0x181b8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181B8Cu;
            // 0x181b90: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181b8c) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181B94u;
label_181b94:
    // 0x181b94: 0x0  nop
    ctx->pc = 0x181b94u;
    // NOP
label_181b98:
    // 0x181b98: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181b98u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181b9c:
    // 0x181b9c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181b9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181ba0:
    // 0x181ba0: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181ba0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181ba4:
    // 0x181ba4: 0x8e06000c  lw          $a2, 0xC($s0)
    ctx->pc = 0x181ba4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_181ba8:
    // 0x181ba8: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x181ba8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_181bac:
    // 0x181bac: 0x8e080014  lw          $t0, 0x14($s0)
    ctx->pc = 0x181bacu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_181bb0:
    // 0x181bb0: 0xc06188c  jal         func_186230
label_181bb4:
    if (ctx->pc == 0x181BB4u) {
        ctx->pc = 0x181BB4u;
            // 0x181bb4: 0x8e090018  lw          $t1, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->pc = 0x181BB8u;
        goto label_181bb8;
    }
    ctx->pc = 0x181BB0u;
    SET_GPR_U32(ctx, 31, 0x181BB8u);
    ctx->pc = 0x181BB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181BB0u;
            // 0x181bb4: 0x8e090018  lw          $t1, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186230u;
    if (runtime->hasFunction(0x186230u)) {
        auto targetFn = runtime->lookupFunction(0x186230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181BB8u; }
        if (ctx->pc != 0x181BB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186230_0x186230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181BB8u; }
        if (ctx->pc != 0x181BB8u) { return; }
    }
    ctx->pc = 0x181BB8u;
label_181bb8:
    // 0x181bb8: 0x10000056  b           . + 4 + (0x56 << 2)
label_181bbc:
    if (ctx->pc == 0x181BBCu) {
        ctx->pc = 0x181BBCu;
            // 0x181bbc: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181BC0u;
        goto label_181bc0;
    }
    ctx->pc = 0x181BB8u;
    {
        const bool branch_taken_0x181bb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181BB8u;
            // 0x181bbc: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181bb8) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181BC0u;
label_181bc0:
    // 0x181bc0: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181bc0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181bc4:
    // 0x181bc4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181bc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181bc8:
    // 0x181bc8: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181bcc:
    // 0x181bcc: 0xc0619e6  jal         func_186798
label_181bd0:
    if (ctx->pc == 0x181BD0u) {
        ctx->pc = 0x181BD0u;
            // 0x181bd0: 0x9606000c  lhu         $a2, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->pc = 0x181BD4u;
        goto label_181bd4;
    }
    ctx->pc = 0x181BCCu;
    SET_GPR_U32(ctx, 31, 0x181BD4u);
    ctx->pc = 0x181BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181BCCu;
            // 0x181bd0: 0x9606000c  lhu         $a2, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186798u;
    if (runtime->hasFunction(0x186798u)) {
        auto targetFn = runtime->lookupFunction(0x186798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181BD4u; }
        if (ctx->pc != 0x181BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186798_0x186798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181BD4u; }
        if (ctx->pc != 0x181BD4u) { return; }
    }
    ctx->pc = 0x181BD4u;
label_181bd4:
    // 0x181bd4: 0x1000004f  b           . + 4 + (0x4F << 2)
label_181bd8:
    if (ctx->pc == 0x181BD8u) {
        ctx->pc = 0x181BD8u;
            // 0x181bd8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181BDCu;
        goto label_181bdc;
    }
    ctx->pc = 0x181BD4u;
    {
        const bool branch_taken_0x181bd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181BD4u;
            // 0x181bd8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181bd4) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181BDCu;
label_181bdc:
    // 0x181bdc: 0x0  nop
    ctx->pc = 0x181bdcu;
    // NOP
label_181be0:
    // 0x181be0: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181be0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181be4:
    // 0x181be4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181be4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181be8:
    // 0x181be8: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181be8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181bec:
    // 0x181bec: 0xc061a32  jal         func_1868C8
label_181bf0:
    if (ctx->pc == 0x181BF0u) {
        ctx->pc = 0x181BF0u;
            // 0x181bf0: 0x2606049c  addiu       $a2, $s0, 0x49C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 1180));
        ctx->pc = 0x181BF4u;
        goto label_181bf4;
    }
    ctx->pc = 0x181BECu;
    SET_GPR_U32(ctx, 31, 0x181BF4u);
    ctx->pc = 0x181BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181BECu;
            // 0x181bf0: 0x2606049c  addiu       $a2, $s0, 0x49C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 1180));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1868C8u;
    if (runtime->hasFunction(0x1868C8u)) {
        auto targetFn = runtime->lookupFunction(0x1868C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181BF4u; }
        if (ctx->pc != 0x181BF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001868C8_0x1868c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181BF4u; }
        if (ctx->pc != 0x181BF4u) { return; }
    }
    ctx->pc = 0x181BF4u;
label_181bf4:
    // 0x181bf4: 0x10000047  b           . + 4 + (0x47 << 2)
label_181bf8:
    if (ctx->pc == 0x181BF8u) {
        ctx->pc = 0x181BF8u;
            // 0x181bf8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181BFCu;
        goto label_181bfc;
    }
    ctx->pc = 0x181BF4u;
    {
        const bool branch_taken_0x181bf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181BF4u;
            // 0x181bf8: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181bf4) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181BFCu;
label_181bfc:
    // 0x181bfc: 0x0  nop
    ctx->pc = 0x181bfcu;
    // NOP
label_181c00:
    // 0x181c00: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181c00u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181c04:
    // 0x181c04: 0xc060ff2  jal         func_183FC8
label_181c08:
    if (ctx->pc == 0x181C08u) {
        ctx->pc = 0x181C08u;
            // 0x181c08: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->pc = 0x181C0Cu;
        goto label_181c0c;
    }
    ctx->pc = 0x181C04u;
    SET_GPR_U32(ctx, 31, 0x181C0Cu);
    ctx->pc = 0x181C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181C04u;
            // 0x181c08: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183FC8u;
    if (runtime->hasFunction(0x183FC8u)) {
        auto targetFn = runtime->lookupFunction(0x183FC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181C0Cu; }
        if (ctx->pc != 0x181C0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183FC8_0x183fc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181C0Cu; }
        if (ctx->pc != 0x181C0Cu) { return; }
    }
    ctx->pc = 0x181C0Cu;
label_181c0c:
    // 0x181c0c: 0x10000041  b           . + 4 + (0x41 << 2)
label_181c10:
    if (ctx->pc == 0x181C10u) {
        ctx->pc = 0x181C10u;
            // 0x181c10: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181C14u;
        goto label_181c14;
    }
    ctx->pc = 0x181C0Cu;
    {
        const bool branch_taken_0x181c0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181C0Cu;
            // 0x181c10: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181c0c) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181C14u;
label_181c14:
    // 0x181c14: 0x0  nop
    ctx->pc = 0x181c14u;
    // NOP
label_181c18:
    // 0x181c18: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181c18u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181c1c:
    // 0x181c1c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181c1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_181c20:
    // 0x181c20: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181c20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181c24:
    // 0x181c24: 0x2605041c  addiu       $a1, $s0, 0x41C
    ctx->pc = 0x181c24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
label_181c28:
    // 0x181c28: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x181c28u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_181c2c:
    // 0x181c2c: 0xc0610d8  jal         func_184360
label_181c30:
    if (ctx->pc == 0x181C30u) {
        ctx->pc = 0x181C30u;
            // 0x181c30: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x181C34u;
        goto label_181c34;
    }
    ctx->pc = 0x181C2Cu;
    SET_GPR_U32(ctx, 31, 0x181C34u);
    ctx->pc = 0x181C30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181C2Cu;
            // 0x181c30: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181C34u; }
        if (ctx->pc != 0x181C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181C34u; }
        if (ctx->pc != 0x181C34u) { return; }
    }
    ctx->pc = 0x181C34u;
label_181c34:
    // 0x181c34: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x181c34u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
label_181c38:
    // 0x181c38: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x181c38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
label_181c3c:
    // 0x181c3c: 0x14430002  bne         $v0, $v1, . + 4 + (0x2 << 2)
label_181c40:
    if (ctx->pc == 0x181C40u) {
        ctx->pc = 0x181C40u;
            // 0x181c40: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181C44u;
        goto label_181c44;
    }
    ctx->pc = 0x181C3Cu;
    {
        const bool branch_taken_0x181c3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x181C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181C3Cu;
            // 0x181c40: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181c3c) {
            ctx->pc = 0x181C48u;
            goto label_181c48;
        }
    }
    ctx->pc = 0x181C44u;
label_181c44:
    // 0x181c44: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x181c44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_181c48:
    // 0x181c48: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181c48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
label_181c4c:
    // 0x181c4c: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x181c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_181c50:
    // 0x181c50: 0x34429fff  ori         $v0, $v0, 0x9FFF
    ctx->pc = 0x181c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40959);
label_181c54:
    // 0x181c54: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
label_181c58:
    if (ctx->pc == 0x181C58u) {
        ctx->pc = 0x181C58u;
            // 0x181c58: 0x8e10000c  lw          $s0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->pc = 0x181C5Cu;
        goto label_181c5c;
    }
    ctx->pc = 0x181C54u;
    {
        const bool branch_taken_0x181c54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x181c54) {
            ctx->pc = 0x181C58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x181C54u;
            // 0x181c58: 0x8e10000c  lw          $s0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x181C6Cu;
            goto label_181c6c;
        }
    }
    ctx->pc = 0x181C5Cu;
label_181c5c:
    // 0x181c5c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
label_181c60:
    // 0x181c60: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x181c60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
label_181c64:
    // 0x181c64: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x181c64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
label_181c68:
    // 0x181c68: 0x8e10000c  lw          $s0, 0xC($s0)
    ctx->pc = 0x181c68u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_181c6c:
    // 0x181c6c: 0x1200002a  beqz        $s0, . + 4 + (0x2A << 2)
label_181c70:
    if (ctx->pc == 0x181C70u) {
        ctx->pc = 0x181C70u;
            // 0x181c70: 0x26629a20  addiu       $v0, $s3, -0x65E0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294941216));
        ctx->pc = 0x181C74u;
        goto label_181c74;
    }
    ctx->pc = 0x181C6Cu;
    {
        const bool branch_taken_0x181c6c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x181C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181C6Cu;
            // 0x181c70: 0x26629a20  addiu       $v0, $s3, -0x65E0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294941216));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181c6c) {
            ctx->pc = 0x181D18u;
            goto label_181d18;
        }
    }
    ctx->pc = 0x181C74u;
label_181c74:
    // 0x181c74: 0x26040018  addiu       $a0, $s0, 0x18
    ctx->pc = 0x181c74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
label_181c78:
    // 0x181c78: 0xc042bf0  jal         func_10AFC0
label_181c7c:
    if (ctx->pc == 0x181C7Cu) {
        ctx->pc = 0x181C7Cu;
            // 0x181c7c: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x181C80u;
        goto label_181c80;
    }
    ctx->pc = 0x181C78u;
    SET_GPR_U32(ctx, 31, 0x181C80u);
    ctx->pc = 0x181C7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181C78u;
            // 0x181c7c: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181C80u; }
        if (ctx->pc != 0x181C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181C80u; }
        if (ctx->pc != 0x181C80u) { return; }
    }
    ctx->pc = 0x181C80u;
label_181c80:
    // 0x181c80: 0x6a820007  ldl         $v0, 0x7($s4)
    ctx->pc = 0x181c80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 20), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
label_181c84:
    // 0x181c84: 0x6e820000  ldr         $v0, 0x0($s4)
    ctx->pc = 0x181c84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 20), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
label_181c88:
    // 0x181c88: 0xb2020007  sdl         $v0, 0x7($s0)
    ctx->pc = 0x181c88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_181c8c:
    // 0x181c8c: 0xb6020000  sdr         $v0, 0x0($s0)
    ctx->pc = 0x181c8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_181c90:
    // 0x181c90: 0x6a460007  ldl         $a2, 0x7($s2)
    ctx->pc = 0x181c90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
label_181c94:
    // 0x181c94: 0x6e460000  ldr         $a2, 0x0($s2)
    ctx->pc = 0x181c94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
label_181c98:
    // 0x181c98: 0xb206000f  sdl         $a2, 0xF($s0)
    ctx->pc = 0x181c98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_181c9c:
    // 0x181c9c: 0xb6060008  sdr         $a2, 0x8($s0)
    ctx->pc = 0x181c9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_181ca0:
    // 0x181ca0: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x181ca0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_181ca4:
    // 0x181ca4: 0x97a20000  lhu         $v0, 0x0($sp)
    ctx->pc = 0x181ca4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
label_181ca8:
    // 0x181ca8: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x181ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
label_181cac:
    // 0x181cac: 0x10000019  b           . + 4 + (0x19 << 2)
label_181cb0:
    if (ctx->pc == 0x181CB0u) {
        ctx->pc = 0x181CB0u;
            // 0x181cb0: 0xa6020014  sh          $v0, 0x14($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 20), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x181CB4u;
        goto label_181cb4;
    }
    ctx->pc = 0x181CACu;
    {
        const bool branch_taken_0x181cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181CACu;
            // 0x181cb0: 0xa6020014  sh          $v0, 0x14($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 20), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181cac) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181CB4u;
label_181cb4:
    // 0x181cb4: 0x0  nop
    ctx->pc = 0x181cb4u;
    // NOP
label_181cb8:
    // 0x181cb8: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181cb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181cbc:
    // 0x181cbc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181cbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181cc0:
    // 0x181cc0: 0xc061aa2  jal         func_186A88
label_181cc4:
    if (ctx->pc == 0x181CC4u) {
        ctx->pc = 0x181CC4u;
            // 0x181cc4: 0x2605041c  addiu       $a1, $s0, 0x41C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
        ctx->pc = 0x181CC8u;
        goto label_181cc8;
    }
    ctx->pc = 0x181CC0u;
    SET_GPR_U32(ctx, 31, 0x181CC8u);
    ctx->pc = 0x181CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181CC0u;
            // 0x181cc4: 0x2605041c  addiu       $a1, $s0, 0x41C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186A88u;
    if (runtime->hasFunction(0x186A88u)) {
        auto targetFn = runtime->lookupFunction(0x186A88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181CC8u; }
        if (ctx->pc != 0x181CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186A88_0x186a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181CC8u; }
        if (ctx->pc != 0x181CC8u) { return; }
    }
    ctx->pc = 0x181CC8u;
label_181cc8:
    // 0x181cc8: 0x10000012  b           . + 4 + (0x12 << 2)
label_181ccc:
    if (ctx->pc == 0x181CCCu) {
        ctx->pc = 0x181CCCu;
            // 0x181ccc: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181CD0u;
        goto label_181cd0;
    }
    ctx->pc = 0x181CC8u;
    {
        const bool branch_taken_0x181cc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181CC8u;
            // 0x181ccc: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181cc8) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181CD0u;
label_181cd0:
    // 0x181cd0: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181cd0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181cd4:
    // 0x181cd4: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x181cd4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_181cd8:
    // 0x181cd8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181cdc:
    // 0x181cdc: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x181cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_181ce0:
    // 0x181ce0: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x181ce0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_181ce4:
    // 0x181ce4: 0xc06204e  jal         func_188138
label_181ce8:
    if (ctx->pc == 0x181CE8u) {
        ctx->pc = 0x181CE8u;
            // 0x181ce8: 0x8e080014  lw          $t0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->pc = 0x181CECu;
        goto label_181cec;
    }
    ctx->pc = 0x181CE4u;
    SET_GPR_U32(ctx, 31, 0x181CECu);
    ctx->pc = 0x181CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181CE4u;
            // 0x181ce8: 0x8e080014  lw          $t0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188138u;
    if (runtime->hasFunction(0x188138u)) {
        auto targetFn = runtime->lookupFunction(0x188138u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181CECu; }
        if (ctx->pc != 0x181CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188138_0x188138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181CECu; }
        if (ctx->pc != 0x181CECu) { return; }
    }
    ctx->pc = 0x181CECu;
label_181cec:
    // 0x181cec: 0x10000009  b           . + 4 + (0x9 << 2)
label_181cf0:
    if (ctx->pc == 0x181CF0u) {
        ctx->pc = 0x181CF0u;
            // 0x181cf0: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x181CF4u;
        goto label_181cf4;
    }
    ctx->pc = 0x181CECu;
    {
        const bool branch_taken_0x181cec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181CECu;
            // 0x181cf0: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181cec) {
            ctx->pc = 0x181D14u;
            goto label_181d14;
        }
    }
    ctx->pc = 0x181CF4u;
label_181cf4:
    // 0x181cf4: 0x0  nop
    ctx->pc = 0x181cf4u;
    // NOP
label_181cf8:
    // 0x181cf8: 0x26309500  addiu       $s0, $s1, -0x6B00
    ctx->pc = 0x181cf8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939904));
label_181cfc:
    // 0x181cfc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x181cfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_181d00:
    // 0x181d00: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x181d00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_181d04:
    // 0x181d04: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x181d04u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_181d08:
    // 0x181d08: 0xc0620d2  jal         func_188348
label_181d0c:
    if (ctx->pc == 0x181D0Cu) {
        ctx->pc = 0x181D0Cu;
            // 0x181d0c: 0x8e070014  lw          $a3, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->pc = 0x181D10u;
        goto label_181d10;
    }
    ctx->pc = 0x181D08u;
    SET_GPR_U32(ctx, 31, 0x181D10u);
    ctx->pc = 0x181D0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181D08u;
            // 0x181d0c: 0x8e070014  lw          $a3, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188348u;
    if (runtime->hasFunction(0x188348u)) {
        auto targetFn = runtime->lookupFunction(0x188348u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D10u; }
        if (ctx->pc != 0x181D10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188348_0x188348(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D10u; }
        if (ctx->pc != 0x181D10u) { return; }
    }
    ctx->pc = 0x181D10u;
label_181d10:
    // 0x181d10: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x181d10u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
label_181d14:
    // 0x181d14: 0x26629a20  addiu       $v0, $s3, -0x65E0
    ctx->pc = 0x181d14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294941216));
label_181d18:
    // 0x181d18: 0xc045190  jal         func_114640
label_181d1c:
    if (ctx->pc == 0x181D1Cu) {
        ctx->pc = 0x181D1Cu;
            // 0x181d1c: 0x8c440008  lw          $a0, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->pc = 0x181D20u;
        goto label_181d20;
    }
    ctx->pc = 0x181D18u;
    SET_GPR_U32(ctx, 31, 0x181D20u);
    ctx->pc = 0x181D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181D18u;
            // 0x181d1c: 0x8c440008  lw          $a0, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D20u; }
        if (ctx->pc != 0x181D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D20u; }
        if (ctx->pc != 0x181D20u) { return; }
    }
    ctx->pc = 0x181D20u;
label_181d20:
    // 0x181d20: 0x1000ff51  b           . + 4 + (-0xAF << 2)
label_181d24:
    if (ctx->pc == 0x181D24u) {
        ctx->pc = 0x181D28u;
        goto label_fallthrough_0x181d20;
    }
    ctx->pc = 0x181D20u;
    {
        const bool branch_taken_0x181d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x181d20) {
            ctx->pc = 0x181A68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_181a68;
        }
    }
label_fallthrough_0x181d20:
    ctx->pc = 0x181D28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

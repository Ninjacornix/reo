#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015A950
// Address: 0x15a950 - 0x15aa70
void sub_0015A950_0x15a950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015A950_0x15a950");
#endif

    switch (ctx->pc) {
        case 0x15a99cu: goto label_15a99c;
        case 0x15a9d4u: goto label_15a9d4;
        case 0x15aa0cu: goto label_15aa0c;
        case 0x15aa24u: goto label_15aa24;
        case 0x15aa3cu: goto label_15aa3c;
        case 0x15aa44u: goto label_15aa44;
        default: break;
    }

    ctx->pc = 0x15a950u;

    // 0x15a950: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15a950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15a954: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x15a954u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x15a958: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15a958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15a95c: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x15a95cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x15a960: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15a960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15a964: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x15a964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x15a968: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x15a968u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a96c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x15a96cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x15a970: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15a970u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a974: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x15a974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x15a978: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x15a978u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a97c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15a97cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15a980: 0x26b40348  addiu       $s4, $s5, 0x348
    ctx->pc = 0x15a980u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 21), 840));
    // 0x15a984: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x15a984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x15a988: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15a988u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a98c: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x15a98cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15a990: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x15a990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x15a994: 0x60f809  jalr        $v1
    ctx->pc = 0x15A994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x15A99Cu);
        ctx->pc = 0x15A998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A994u;
            // 0x15a998: 0x280382d  daddu       $a3, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A99Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A99Cu: goto label_15a99c;
            case 0x15A9CCu: goto label_15a9cc;
            case 0x15A9D4u: goto label_15a9d4;
            case 0x15AA0Cu: goto label_15aa0c;
            case 0x15AA24u: goto label_15aa24;
            case 0x15AA3Cu: goto label_15aa3c;
            case 0x15AA44u: goto label_15aa44;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A99Cu; }
            if (ctx->pc != 0x15A99Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15A99Cu;
label_15a99c:
    // 0x15a99c: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x15a99cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a9a0: 0x8e820000  lw          $v0, 0x0($s4)
    ctx->pc = 0x15a9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x15a9a4: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x15a9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x15a9a8: 0x439024  and         $s2, $v0, $v1
    ctx->pc = 0x15a9a8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x15a9ac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15a9acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a9b0: 0x521023  subu        $v0, $v0, $s2
    ctx->pc = 0x15a9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x15a9b4: 0x288c0  sll         $s1, $v0, 3
    ctx->pc = 0x15a9b4u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x15a9b8: 0x2a230020  slti        $v1, $s1, 0x20
    ctx->pc = 0x15a9b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15a9bc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15A9BCu;
    {
        const bool branch_taken_0x15a9bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A9C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A9BCu;
            // 0x15a9c0: 0x26520008  addiu       $s2, $s2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a9bc) {
            ctx->pc = 0x15A9CCu;
            goto label_15a9cc;
        }
    }
    ctx->pc = 0x15A9C4u;
    // 0x15a9c4: 0x2631ffe0  addiu       $s1, $s1, -0x20
    ctx->pc = 0x15a9c4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967264));
    // 0x15a9c8: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x15a9c8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
label_15a9cc:
    // 0x15a9cc: 0xc056a9c  jal         func_15AA70
    ctx->pc = 0x15A9CCu;
    SET_GPR_U32(ctx, 31, 0x15A9D4u);
    ctx->pc = 0x15A9D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15A9CCu;
            // 0x15a9d0: 0x8ea6034c  lw          $a2, 0x34C($s5) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 844)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15AA70u;
    if (runtime->hasFunction(0x15AA70u)) {
        auto targetFn = runtime->lookupFunction(0x15AA70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A9D4u; }
        if (ctx->pc != 0x15A9D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015AA70_0x15aa70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A9D4u; }
        if (ctx->pc != 0x15A9D4u) { return; }
    }
    ctx->pc = 0x15A9D4u;
label_15a9d4:
    // 0x15a9d4: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x15a9d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x15a9d8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15a9d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a9dc: 0x32220007  andi        $v0, $s1, 0x7
    ctx->pc = 0x15a9dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)7);
    // 0x15a9e0: 0x2222823  subu        $a1, $s1, $v0
    ctx->pc = 0x15a9e0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x15a9e4: 0xaea20350  sw          $v0, 0x350($s5)
    ctx->pc = 0x15a9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 848), GPR_U32(ctx, 2));
    // 0x15a9e8: 0x24a50007  addiu       $a1, $a1, 0x7
    ctx->pc = 0x15a9e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x15a9ec: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x15a9ecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a9f0: 0x528c3  sra         $a1, $a1, 3
    ctx->pc = 0x15a9f0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 3));
    // 0x15a9f4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x15a9f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a9f8: 0x2452821  addu        $a1, $s2, $a1
    ctx->pc = 0x15a9f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x15a9fc: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x15a9fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa00: 0x24a5fffc  addiu       $a1, $a1, -0x4
    ctx->pc = 0x15aa00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967292));
    // 0x15aa04: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x15AA04u;
    SET_GPR_U32(ctx, 31, 0x15AA0Cu);
    ctx->pc = 0x15AA08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AA04u;
            // 0x15aa08: 0xa32823  subu        $a1, $a1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AA0Cu; }
        if (ctx->pc != 0x15AA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AA0Cu; }
        if (ctx->pc != 0x15AA0Cu) { return; }
    }
    ctx->pc = 0x15AA0Cu;
label_15aa0c:
    // 0x15aa0c: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x15aa0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15aa10: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x15aa10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa14: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15aa14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa18: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15aa18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15aa1c: 0x40f809  jalr        $v0
    ctx->pc = 0x15AA1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AA24u);
        ctx->pc = 0x15AA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AA1Cu;
            // 0x15aa20: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AA24u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A99Cu: goto label_15a99c;
            case 0x15A9CCu: goto label_15a9cc;
            case 0x15A9D4u: goto label_15a9d4;
            case 0x15AA0Cu: goto label_15aa0c;
            case 0x15AA24u: goto label_15aa24;
            case 0x15AA3Cu: goto label_15aa3c;
            case 0x15AA44u: goto label_15aa44;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AA24u; }
            if (ctx->pc != 0x15AA24u) { return; }
        }
        }
    }
    ctx->pc = 0x15AA24u;
label_15aa24:
    // 0x15aa24: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x15aa24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15aa28: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15aa28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15aa2c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x15aa2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa30: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15aa30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15aa34: 0x40f809  jalr        $v0
    ctx->pc = 0x15AA34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AA3Cu);
        ctx->pc = 0x15AA38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AA34u;
            // 0x15aa38: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AA3Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A99Cu: goto label_15a99c;
            case 0x15A9CCu: goto label_15a9cc;
            case 0x15A9D4u: goto label_15a9d4;
            case 0x15AA0Cu: goto label_15aa0c;
            case 0x15AA24u: goto label_15aa24;
            case 0x15AA3Cu: goto label_15aa3c;
            case 0x15AA44u: goto label_15aa44;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AA3Cu; }
            if (ctx->pc != 0x15AA3Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15AA3Cu;
label_15aa3c:
    // 0x15aa3c: 0xc056b7a  jal         func_15ADE8
    ctx->pc = 0x15AA3Cu;
    SET_GPR_U32(ctx, 31, 0x15AA44u);
    ctx->pc = 0x15AA40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AA3Cu;
            // 0x15aa40: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15ADE8u;
    if (runtime->hasFunction(0x15ADE8u)) {
        auto targetFn = runtime->lookupFunction(0x15ADE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AA44u; }
        if (ctx->pc != 0x15AA44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015ADE8_0x15ade8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AA44u; }
        if (ctx->pc != 0x15AA44u) { return; }
    }
    ctx->pc = 0x15AA44u;
label_15aa44:
    // 0x15aa44: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15aa44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa48: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15aa48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15aa4c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15aa4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15aa50: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15aa50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15aa54: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x15aa54u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15aa58: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x15aa58u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15aa5c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x15aa5cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15aa60: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x15aa60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15aa64: 0x3e00008  jr          $ra
    ctx->pc = 0x15AA64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15AA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AA64u;
            // 0x15aa68: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A99Cu: goto label_15a99c;
            case 0x15A9CCu: goto label_15a9cc;
            case 0x15A9D4u: goto label_15a9d4;
            case 0x15AA0Cu: goto label_15aa0c;
            case 0x15AA24u: goto label_15aa24;
            case 0x15AA3Cu: goto label_15aa3c;
            case 0x15AA44u: goto label_15aa44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15AA6Cu;
    // 0x15aa6c: 0x0  nop
    ctx->pc = 0x15aa6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FCE0
// Address: 0x12fce0 - 0x12fff8
void sub_0012FCE0_0x12fce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FCE0_0x12fce0");
#endif

    switch (ctx->pc) {
        case 0x12fd04u: goto label_12fd04;
        case 0x12fd10u: goto label_12fd10;
        case 0x12fd1cu: goto label_12fd1c;
        case 0x12fd60u: goto label_12fd60;
        case 0x12fd78u: goto label_12fd78;
        case 0x12fe28u: goto label_12fe28;
        case 0x12fe58u: goto label_12fe58;
        case 0x12fe84u: goto label_12fe84;
        case 0x12feb8u: goto label_12feb8;
        case 0x12fee4u: goto label_12fee4;
        case 0x12ff10u: goto label_12ff10;
        case 0x12ff24u: goto label_12ff24;
        case 0x12ff74u: goto label_12ff74;
        case 0x12ff88u: goto label_12ff88;
        case 0x12ffb0u: goto label_12ffb0;
        case 0x12ffd0u: goto label_12ffd0;
        default: break;
    }

    ctx->pc = 0x12fce0u;

    // 0x12fce0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12fce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12fce4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12fce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12fce8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x12fce8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fcec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12fcecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12fcf0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12fcf0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fcf4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12fcf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12fcf8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12fcf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12fcfc: 0xc04bec2  jal         func_12FB08
    ctx->pc = 0x12FCFCu;
    SET_GPR_U32(ctx, 31, 0x12FD04u);
    ctx->pc = 0x12FD00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FCFCu;
            // 0x12fd00: 0xe0902d  daddu       $s2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FB08u;
    if (runtime->hasFunction(0x12FB08u)) {
        auto targetFn = runtime->lookupFunction(0x12FB08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD04u; }
        if (ctx->pc != 0x12FD04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FB08_0x12fb08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD04u; }
        if (ctx->pc != 0x12FD04u) { return; }
    }
    ctx->pc = 0x12FD04u;
label_12fd04:
    // 0x12fd04: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12fd04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd08: 0xc04bebe  jal         func_12FAF8
    ctx->pc = 0x12FD08u;
    SET_GPR_U32(ctx, 31, 0x12FD10u);
    ctx->pc = 0x12FD0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD08u;
            // 0x12fd0c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FAF8u;
    if (runtime->hasFunction(0x12FAF8u)) {
        auto targetFn = runtime->lookupFunction(0x12FAF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD10u; }
        if (ctx->pc != 0x12FD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FAF8_0x12faf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD10u; }
        if (ctx->pc != 0x12FD10u) { return; }
    }
    ctx->pc = 0x12FD10u;
label_12fd10:
    // 0x12fd10: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12fd10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd14: 0xc04bee2  jal         func_12FB88
    ctx->pc = 0x12FD14u;
    SET_GPR_U32(ctx, 31, 0x12FD1Cu);
    ctx->pc = 0x12FD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD14u;
            // 0x12fd18: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FB88u;
    if (runtime->hasFunction(0x12FB88u)) {
        auto targetFn = runtime->lookupFunction(0x12FB88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD1Cu; }
        if (ctx->pc != 0x12FD1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FB88_0x12fb88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD1Cu; }
        if (ctx->pc != 0x12FD1Cu) { return; }
    }
    ctx->pc = 0x12FD1Cu;
label_12fd1c:
    // 0x12fd1c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12fd1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12fd20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fd24: 0x2405011c  addiu       $a1, $zero, 0x11C
    ctx->pc = 0x12fd24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 284));
    // 0x12fd28: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12fd28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12fd2c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12fd2cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12fd30: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12fd30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12fd34: 0x804bec0  j           func_12FB00
    ctx->pc = 0x12FD34u;
    ctx->pc = 0x12FD38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD34u;
            // 0x12fd38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FB00u;
    if (runtime->hasFunction(0x12FB00u)) {
        auto targetFn = runtime->lookupFunction(0x12FB00u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012FB00_0x12fb00(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12FD3Cu;
    // 0x12fd3c: 0x0  nop
    ctx->pc = 0x12fd3cu;
    // NOP
    // 0x12fd40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12fd40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12fd44: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12fd44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12fd48: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x12fd48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd4c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12fd4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12fd50: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12fd50u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd54: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12fd54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12fd58: 0xc042c56  jal         func_10B158
    ctx->pc = 0x12FD58u;
    SET_GPR_U32(ctx, 31, 0x12FD60u);
    ctx->pc = 0x12FD5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD58u;
            // 0x12fd5c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD60u; }
        if (ctx->pc != 0x12FD60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD60u; }
        if (ctx->pc != 0x12FD60u) { return; }
    }
    ctx->pc = 0x12FD60u;
label_12fd60:
    // 0x12fd60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12fd60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd64: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12fd64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd68: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12fd68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd6c: 0x27a70002  addiu       $a3, $sp, 0x2
    ctx->pc = 0x12fd6cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 2));
    // 0x12fd70: 0xc04b6c0  jal         func_12DB00
    ctx->pc = 0x12FD70u;
    SET_GPR_U32(ctx, 31, 0x12FD78u);
    ctx->pc = 0x12FD74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD70u;
            // 0x12fd74: 0x27a80004  addiu       $t0, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DB00u;
    if (runtime->hasFunction(0x12DB00u)) {
        auto targetFn = runtime->lookupFunction(0x12DB00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD78u; }
        if (ctx->pc != 0x12FD78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DB00_0x12db00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD78u; }
        if (ctx->pc != 0x12FD78u) { return; }
    }
    ctx->pc = 0x12FD78u;
label_12fd78:
    // 0x12fd78: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x12fd78u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fd7c: 0x97a40002  lhu         $a0, 0x2($sp)
    ctx->pc = 0x12fd7cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x12fd80: 0x97a20004  lhu         $v0, 0x4($sp)
    ctx->pc = 0x12fd80u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12fd84: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12fd84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12fd88: 0xa62302d0  sh          $v1, 0x2D0($s1)
    ctx->pc = 0x12fd88u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 720), (uint16_t)GPR_U32(ctx, 3));
    // 0x12fd8c: 0xa62202d4  sh          $v0, 0x2D4($s1)
    ctx->pc = 0x12fd8cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 724), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fd90: 0xa62402d2  sh          $a0, 0x2D2($s1)
    ctx->pc = 0x12fd90u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 722), (uint16_t)GPR_U32(ctx, 4));
    // 0x12fd94: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12fd94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12fd98: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12fd98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12fd9c: 0x3e00008  jr          $ra
    ctx->pc = 0x12FD9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD9Cu;
            // 0x12fda0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDA4u;
    // 0x12fda4: 0x0  nop
    ctx->pc = 0x12fda4u;
    // NOP
    // 0x12fda8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDA8u;
            // 0x12fdac: 0x8c82002c  lw          $v0, 0x2C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDB0u;
    // 0x12fdb0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDB0u;
            // 0x12fdb4: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDB8u;
    // 0x12fdb8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDB8u;
            // 0x12fdbc: 0xac850030  sw          $a1, 0x30($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDC0u;
    // 0x12fdc0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDC0u;
            // 0x12fdc4: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDC8u;
    // 0x12fdc8: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x12fdc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12fdcc: 0x2ca50002  sltiu       $a1, $a1, 0x2
    ctx->pc = 0x12fdccu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x12fdd0: 0x10a00002  beqz        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x12FDD0u;
    {
        const bool branch_taken_0x12fdd0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDD0u;
            // 0x12fdd4: 0x822021  addu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fdd0) {
            ctx->pc = 0x12FDDCu;
            goto label_12fddc;
        }
    }
    ctx->pc = 0x12FDD8u;
    // 0x12fdd8: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x12fdd8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
label_12fddc:
    // 0x12fddc: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDE4u;
    // 0x12fde4: 0x0  nop
    ctx->pc = 0x12fde4u;
    // NOP
    // 0x12fde8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDE8u;
            // 0x12fdec: 0xac85000c  sw          $a1, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDF0u;
    // 0x12fdf0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12fdf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12fdf4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12fdf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12fdf8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12fdf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12fdfc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12fdfcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fe00: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12fe00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x12fe04: 0x263202c8  addiu       $s2, $s1, 0x2C8
    ctx->pc = 0x12fe04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 712));
    // 0x12fe08: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12fe08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x12fe0c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x12fe0cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fe10: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x12fe10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x12fe14: 0x26300004  addiu       $s0, $s1, 0x4
    ctx->pc = 0x12fe14u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x12fe18: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12fe18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12fe1c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x12FE1Cu;
    {
        const bool branch_taken_0x12fe1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE1Cu;
            // 0x12fe20: 0x8e34000c  lw          $s4, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fe1c) {
            ctx->pc = 0x12FE58u;
            goto label_12fe58;
        }
    }
    ctx->pc = 0x12FE24u;
    // 0x12fe24: 0x0  nop
    ctx->pc = 0x12fe24u;
    // NOP
label_12fe28:
    // 0x12fe28: 0x8e070000  lw          $a3, 0x0($s0)
    ctx->pc = 0x12fe28u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12fe2c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x12fe2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12fe30: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x12fe30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fe34: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x12fe34u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x12fe38: 0x8ce80000  lw          $t0, 0x0($a3)
    ctx->pc = 0x12fe38u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12fe3c: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x12fe3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fe40: 0x94620000  lhu         $v0, 0x0($v1)
    ctx->pc = 0x12fe40u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12fe44: 0xa6420000  sh          $v0, 0x0($s2)
    ctx->pc = 0x12fe44u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fe48: 0xa6420004  sh          $v0, 0x4($s2)
    ctx->pc = 0x12fe48u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fe4c: 0x8d02001c  lw          $v0, 0x1C($t0)
    ctx->pc = 0x12fe4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 28)));
    // 0x12fe50: 0x40f809  jalr        $v0
    ctx->pc = 0x12FE50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12FE58u);
        ctx->pc = 0x12FE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE50u;
            // 0x12fe54: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FE58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FE58u; }
            if (ctx->pc != 0x12FE58u) { return; }
        }
        }
    }
    ctx->pc = 0x12FE58u;
label_12fe58:
    // 0x12fe58: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fe58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12fe5c: 0x263102a  slt         $v0, $s3, $v1
    ctx->pc = 0x12fe5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12fe60: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x12FE60u;
    {
        const bool branch_taken_0x12fe60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FE64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE60u;
            // 0x12fe64: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fe60) {
            ctx->pc = 0x12FEA4u;
            goto label_12fea4;
        }
    }
    ctx->pc = 0x12FE68u;
    // 0x12fe68: 0x8e080000  lw          $t0, 0x0($s0)
    ctx->pc = 0x12fe68u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12fe6c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12fe6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fe70: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x12fe70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12fe74: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x12fe74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x12fe78: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12fe78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12fe7c: 0x60f809  jalr        $v1
    ctx->pc = 0x12FE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12FE84u);
        ctx->pc = 0x12FE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE7Cu;
            // 0x12fe80: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FE84u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FE84u; }
            if (ctx->pc != 0x12FE84u) { return; }
        }
        }
    }
    ctx->pc = 0x12FE84u;
label_12fe84:
    // 0x12fe84: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12fe84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fe88: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x12fe88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12fe8c: 0x1440ffe6  bnez        $v0, . + 4 + (-0x1A << 2)
    ctx->pc = 0x12FE8Cu;
    {
        const bool branch_taken_0x12fe8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE8Cu;
            // 0x12fe90: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fe8c) {
            ctx->pc = 0x12FE28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12fe28;
        }
    }
    ctx->pc = 0x12FE94u;
    // 0x12fe94: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fe94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12fe98: 0x263102a  slt         $v0, $s3, $v1
    ctx->pc = 0x12fe98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12fe9c: 0x54400028  bnel        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x12FE9Cu;
    {
        const bool branch_taken_0x12fe9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12fe9c) {
            ctx->pc = 0x12FEA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE9Cu;
            // 0x12fea0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FF40u;
            goto label_12ff40;
        }
    }
    ctx->pc = 0x12FEA4u;
label_12fea4:
    // 0x12fea4: 0x5860000d  blezl       $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x12FEA4u;
    {
        const bool branch_taken_0x12fea4 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x12fea4) {
            ctx->pc = 0x12FEA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEA4u;
            // 0x12fea8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FEDCu;
            goto label_12fedc;
        }
    }
    ctx->pc = 0x12FEACu;
    // 0x12feac: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12feacu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12feb0: 0x26230088  addiu       $v1, $s1, 0x88
    ctx->pc = 0x12feb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 136));
    // 0x12feb4: 0x2624008c  addiu       $a0, $s1, 0x8C
    ctx->pc = 0x12feb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
label_12feb8:
    // 0x12feb8: 0x94620240  lhu         $v0, 0x240($v1)
    ctx->pc = 0x12feb8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 576)));
    // 0x12febc: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x12febcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x12fec0: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x12fec0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fec4: 0x24630002  addiu       $v1, $v1, 0x2
    ctx->pc = 0x12fec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x12fec8: 0x94820240  lhu         $v0, 0x240($a0)
    ctx->pc = 0x12fec8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 576)));
    // 0x12fecc: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x12feccu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fed0: 0x1660fff9  bnez        $s3, . + 4 + (-0x7 << 2)
    ctx->pc = 0x12FED0u;
    {
        const bool branch_taken_0x12fed0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FED0u;
            // 0x12fed4: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fed0) {
            ctx->pc = 0x12FEB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12feb8;
        }
    }
    ctx->pc = 0x12FED8u;
    // 0x12fed8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12fed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12fedc:
    // 0x12fedc: 0xc04bc24  jal         func_12F090
    ctx->pc = 0x12FEDCu;
    SET_GPR_U32(ctx, 31, 0x12FEE4u);
    ctx->pc = 0x12FEE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEDCu;
            // 0x12fee0: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12F090u;
    if (runtime->hasFunction(0x12F090u)) {
        auto targetFn = runtime->lookupFunction(0x12F090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FEE4u; }
        if (ctx->pc != 0x12FEE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F090_0x12f090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FEE4u; }
        if (ctx->pc != 0x12FEE4u) { return; }
    }
    ctx->pc = 0x12FEE4u;
label_12fee4:
    // 0x12fee4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12fee4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fee8: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x12FEE8u;
    {
        const bool branch_taken_0x12fee8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEE8u;
            // 0x12feec: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fee8) {
            ctx->pc = 0x12FF3Cu;
            goto label_12ff3c;
        }
    }
    ctx->pc = 0x12FEF0u;
    // 0x12fef0: 0x8e22002c  lw          $v0, 0x2C($s1)
    ctx->pc = 0x12fef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x12fef4: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12fef8: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12fef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12fefc: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x12FEFCu;
    {
        const bool branch_taken_0x12fefc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12FF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEFCu;
            // 0x12ff00: 0xae22002c  sw          $v0, 0x2C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fefc) {
            ctx->pc = 0x12FF34u;
            goto label_12ff34;
        }
    }
    ctx->pc = 0x12FF04u;
    // 0x12ff04: 0x26300080  addiu       $s0, $s1, 0x80
    ctx->pc = 0x12ff04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x12ff08: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12ff08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12ff0c: 0x0  nop
    ctx->pc = 0x12ff0cu;
    // NOP
label_12ff10:
    // 0x12ff10: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x12ff10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12ff14: 0x8e250064  lw          $a1, 0x64($s1)
    ctx->pc = 0x12ff14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 100)));
    // 0x12ff18: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x12ff18u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x12ff1c: 0xc04b8da  jal         func_12E368
    ctx->pc = 0x12FF1Cu;
    SET_GPR_U32(ctx, 31, 0x12FF24u);
    ctx->pc = 0x12FF20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF1Cu;
            // 0x12ff20: 0x8e26005c  lw          $a2, 0x5C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 92)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E368u;
    if (runtime->hasFunction(0x12E368u)) {
        auto targetFn = runtime->lookupFunction(0x12E368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FF24u; }
        if (ctx->pc != 0x12FF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E368_0x12e368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FF24u; }
        if (ctx->pc != 0x12FF24u) { return; }
    }
    ctx->pc = 0x12FF24u;
label_12ff24:
    // 0x12ff24: 0x8e220058  lw          $v0, 0x58($s1)
    ctx->pc = 0x12ff24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12ff28: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x12ff28u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12ff2c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12FF2Cu;
    {
        const bool branch_taken_0x12ff2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ff2c) {
            ctx->pc = 0x12FF30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF2Cu;
            // 0x12ff30: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FF10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ff10;
        }
    }
    ctx->pc = 0x12FF34u;
label_12ff34:
    // 0x12ff34: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12ff34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12ff38: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x12ff38u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
label_12ff3c:
    // 0x12ff3c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12ff3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_12ff40:
    // 0x12ff40: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12ff40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ff44: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12ff44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ff48: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12ff48u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ff4c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x12ff4cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ff50: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12ff50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12ff54: 0x3e00008  jr          $ra
    ctx->pc = 0x12FF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF54u;
            // 0x12ff58: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FF5Cu;
    // 0x12ff5c: 0x0  nop
    ctx->pc = 0x12ff5cu;
    // NOP
    // 0x12ff60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12ff60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12ff64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ff64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ff68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12ff68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12ff6c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ff6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ff70: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12ff70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_12ff74:
    // 0x12ff74: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x12ff74u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x12ff78: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x12FF78u;
    {
        const bool branch_taken_0x12ff78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF78u;
            // 0x12ff7c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ff78) {
            ctx->pc = 0x12FFC8u;
            goto label_12ffc8;
        }
    }
    ctx->pc = 0x12FF80u;
    // 0x12ff80: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x12FF80u;
    {
        const bool branch_taken_0x12ff80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12ff80) {
            ctx->pc = 0x12FFA8u;
            goto label_12ffa8;
        }
    }
    ctx->pc = 0x12FF88u;
label_12ff88:
    // 0x12ff88: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x12ff88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x12ff8c: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x12ff8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x12ff90: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x12ff90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12ff94: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x12ff94u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12ff98: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12FF98u;
    {
        const bool branch_taken_0x12ff98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF98u;
            // 0x12ff9c: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ff98) {
            ctx->pc = 0x12FFA8u;
            goto label_12ffa8;
        }
    }
    ctx->pc = 0x12FFA0u;
    // 0x12ffa0: 0x1000fff4  b           . + 4 + (-0xC << 2)
    ctx->pc = 0x12FFA0u;
    {
        const bool branch_taken_0x12ffa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FFA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFA0u;
            // 0x12ffa4: 0xa2110003  sb          $s1, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ffa0) {
            ctx->pc = 0x12FF74u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ff74;
        }
    }
    ctx->pc = 0x12FFA8u;
label_12ffa8:
    // 0x12ffa8: 0xc04bbb8  jal         func_12EEE0
    ctx->pc = 0x12FFA8u;
    SET_GPR_U32(ctx, 31, 0x12FFB0u);
    ctx->pc = 0x12FFACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFA8u;
            // 0x12ffac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12EEE0u;
    if (runtime->hasFunction(0x12EEE0u)) {
        auto targetFn = runtime->lookupFunction(0x12EEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFB0u; }
        if (ctx->pc != 0x12FFB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012EEE0_0x12eee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFB0u; }
        if (ctx->pc != 0x12FFB0u) { return; }
    }
    ctx->pc = 0x12FFB0u;
label_12ffb0:
    // 0x12ffb0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12ffb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ffb4: 0x54a0fff4  bnel        $a1, $zero, . + 4 + (-0xC << 2)
    ctx->pc = 0x12FFB4u;
    {
        const bool branch_taken_0x12ffb4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ffb4) {
            ctx->pc = 0x12FFB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFB4u;
            // 0x12ffb8: 0x8e02002c  lw          $v0, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FF88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ff88;
        }
    }
    ctx->pc = 0x12FFBCu;
    // 0x12ffbc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x12FFBCu;
    {
        const bool branch_taken_0x12ffbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFBCu;
            // 0x12ffc0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ffbc) {
            ctx->pc = 0x12FFE4u;
            goto label_12ffe4;
        }
    }
    ctx->pc = 0x12FFC4u;
    // 0x12ffc4: 0x0  nop
    ctx->pc = 0x12ffc4u;
    // NOP
label_12ffc8:
    // 0x12ffc8: 0xc04bbe4  jal         func_12EF90
    ctx->pc = 0x12FFC8u;
    SET_GPR_U32(ctx, 31, 0x12FFD0u);
    ctx->pc = 0x12FFCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFC8u;
            // 0x12ffcc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12EF90u;
    if (runtime->hasFunction(0x12EF90u)) {
        auto targetFn = runtime->lookupFunction(0x12EF90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFD0u; }
        if (ctx->pc != 0x12FFD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012EF90_0x12ef90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFD0u; }
        if (ctx->pc != 0x12FFD0u) { return; }
    }
    ctx->pc = 0x12FFD0u;
label_12ffd0:
    // 0x12ffd0: 0x58400004  blezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12FFD0u;
    {
        const bool branch_taken_0x12ffd0 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x12ffd0) {
            ctx->pc = 0x12FFD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFD0u;
            // 0x12ffd4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FFE4u;
            goto label_12ffe4;
        }
    }
    ctx->pc = 0x12FFD8u;
    // 0x12ffd8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12ffd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12ffdc: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x12ffdcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12ffe0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ffe0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12ffe4:
    // 0x12ffe4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ffe4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ffe8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12ffe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ffec: 0x3e00008  jr          $ra
    ctx->pc = 0x12FFECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFECu;
            // 0x12fff0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD04u: goto label_12fd04;
            case 0x12FD10u: goto label_12fd10;
            case 0x12FD1Cu: goto label_12fd1c;
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            case 0x12FDDCu: goto label_12fddc;
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FFF4u;
    // 0x12fff4: 0x0  nop
    ctx->pc = 0x12fff4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

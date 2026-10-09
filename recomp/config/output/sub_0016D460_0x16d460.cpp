#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D460
// Address: 0x16d460 - 0x16d508
void sub_0016D460_0x16d460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D460_0x16d460");
#endif

    switch (ctx->pc) {
        case 0x16d4acu: goto label_16d4ac;
        case 0x16d4e0u: goto label_16d4e0;
        default: break;
    }

    ctx->pc = 0x16d460u;

    // 0x16d460: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16d460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16d464: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x16d464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x16d468: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16d468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16d46c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16d46cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d470: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16d470u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16d474: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16d474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16d478: 0x244205a8  addiu       $v0, $v0, 0x5A8
    ctx->pc = 0x16d478u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1448));
    // 0x16d47c: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x16d47cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16d480: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x16d480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x16d484: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16D484u;
    {
        const bool branch_taken_0x16d484 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16D488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D484u;
            // 0x16d488: 0x26110cc0  addiu       $s1, $s0, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d484) {
            ctx->pc = 0x16D4A0u;
            goto label_16d4a0;
        }
    }
    ctx->pc = 0x16D48Cu;
    // 0x16d48c: 0x3402ac44  ori         $v0, $zero, 0xAC44
    ctx->pc = 0x16d48cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)44100);
    // 0x16d490: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x16d490u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x16d494: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x16D494u;
    {
        const bool branch_taken_0x16d494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D494u;
            // 0x16d498: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d494) {
            ctx->pc = 0x16D4C0u;
            goto label_16d4c0;
        }
    }
    ctx->pc = 0x16D49Cu;
    // 0x16d49c: 0x0  nop
    ctx->pc = 0x16d49cu;
    // NOP
label_16d4a0:
    // 0x16d4a0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16d4a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d4a4: 0xc059ff0  jal         func_167FC0
    ctx->pc = 0x16D4A4u;
    SET_GPR_U32(ctx, 31, 0x16D4ACu);
    ctx->pc = 0x16D4A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D4A4u;
            // 0x16d4a8: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167FC0u;
    if (runtime->hasFunction(0x167FC0u)) {
        auto targetFn = runtime->lookupFunction(0x167FC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D4ACu; }
        if (ctx->pc != 0x16D4ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167FC0_0x167fc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D4ACu; }
        if (ctx->pc != 0x16D4ACu) { return; }
    }
    ctx->pc = 0x16D4ACu;
label_16d4ac:
    // 0x16d4ac: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D4ACu;
    {
        const bool branch_taken_0x16d4ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16D4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D4ACu;
            // 0x16d4b0: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d4ac) {
            ctx->pc = 0x16D4C4u;
            goto label_16d4c4;
        }
    }
    ctx->pc = 0x16D4B4u;
    // 0x16d4b4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x16D4B4u;
    {
        const bool branch_taken_0x16d4b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D4B4u;
            // 0x16d4b8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d4b4) {
            ctx->pc = 0x16D4F0u;
            goto label_16d4f0;
        }
    }
    ctx->pc = 0x16D4BCu;
    // 0x16d4bc: 0x0  nop
    ctx->pc = 0x16d4bcu;
    // NOP
label_16d4c0:
    // 0x16d4c0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x16d4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_16d4c4:
    // 0x16d4c4: 0x8e2201ac  lw          $v0, 0x1AC($s1)
    ctx->pc = 0x16d4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 428)));
    // 0x16d4c8: 0x8e050d00  lw          $a1, 0xD00($s0)
    ctx->pc = 0x16d4c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3328)));
    // 0x16d4cc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16d4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16d4d0: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x16d4d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16d4d4: 0xae2201ac  sw          $v0, 0x1AC($s1)
    ctx->pc = 0x16d4d4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 428), GPR_U32(ctx, 2));
    // 0x16d4d8: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x16D4D8u;
    SET_GPR_U32(ctx, 31, 0x16D4E0u);
    ctx->pc = 0x16D4DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D4D8u;
            // 0x16d4dc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D4E0u; }
        if (ctx->pc != 0x16D4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D4E0u; }
        if (ctx->pc != 0x16D4E0u) { return; }
    }
    ctx->pc = 0x16D4E0u;
label_16d4e0:
    // 0x16d4e0: 0x8e230120  lw          $v1, 0x120($s1)
    ctx->pc = 0x16d4e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 288)));
    // 0x16d4e4: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x16d4e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16d4e8: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x16d4e8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16d4ec: 0x4100b  movn        $v0, $zero, $a0
    ctx->pc = 0x16d4ecu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_16d4f0:
    // 0x16d4f0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16d4f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d4f4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16d4f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d4f8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16d4f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16d4fc: 0x3e00008  jr          $ra
    ctx->pc = 0x16D4FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D4FCu;
            // 0x16d500: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D4A0u: goto label_16d4a0;
            case 0x16D4ACu: goto label_16d4ac;
            case 0x16D4C0u: goto label_16d4c0;
            case 0x16D4C4u: goto label_16d4c4;
            case 0x16D4E0u: goto label_16d4e0;
            case 0x16D4F0u: goto label_16d4f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D504u;
    // 0x16d504: 0x0  nop
    ctx->pc = 0x16d504u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

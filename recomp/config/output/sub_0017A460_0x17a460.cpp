#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A460
// Address: 0x17a460 - 0x17a4e4
void sub_0017A460_0x17a460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A460_0x17a460");
#endif

    switch (ctx->pc) {
        case 0x17a48cu: goto label_17a48c;
        case 0x17a4a4u: goto label_17a4a4;
        default: break;
    }

    ctx->pc = 0x17a460u;

    // 0x17a460: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17a460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17a464: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a468: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a468u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a46c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a46cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a470: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a470u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a474: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a478: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17a478u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a47c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17a47cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17a480: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17a480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17a484: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A484u;
    SET_GPR_U32(ctx, 31, 0x17A48Cu);
    ctx->pc = 0x17A488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A484u;
            // 0x17a488: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A48Cu; }
        if (ctx->pc != 0x17A48Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A48Cu; }
        if (ctx->pc != 0x17A48Cu) { return; }
    }
    ctx->pc = 0x17A48Cu;
label_17a48c:
    // 0x17a48c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a48cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a490: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a490u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a494: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A494u;
    {
        const bool branch_taken_0x17a494 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A494u;
            // 0x17a498: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a494) {
            ctx->pc = 0x17A4C8u;
            goto label_17a4c8;
        }
    }
    ctx->pc = 0x17A49Cu;
    // 0x17a49c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A49Cu;
    SET_GPR_U32(ctx, 31, 0x17A4A4u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A4A4u; }
        if (ctx->pc != 0x17A4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A4A4u; }
        if (ctx->pc != 0x17A4A4u) { return; }
    }
    ctx->pc = 0x17A4A4u;
label_17a4a4:
    // 0x17a4a4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A4A4u;
    {
        const bool branch_taken_0x17a4a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A4A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A4A4u;
            // 0x17a4a8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a4a4) {
            ctx->pc = 0x17A4CCu;
            goto label_17a4cc;
        }
    }
    ctx->pc = 0x17A4ACu;
    // 0x17a4ac: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x17a4acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x17a4b0: 0x286300d2  slti        $v1, $v1, 0xD2
    ctx->pc = 0x17a4b0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)210) ? 1 : 0);
    // 0x17a4b4: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A4B4u;
    {
        const bool branch_taken_0x17a4b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A4B4u;
            // 0x17a4b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a4b4) {
            ctx->pc = 0x17A4CCu;
            goto label_17a4cc;
        }
    }
    ctx->pc = 0x17A4BCu;
    // 0x17a4bc: 0x92230027  lbu         $v1, 0x27($s1)
    ctx->pc = 0x17a4bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 39)));
    // 0x17a4c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a4c4: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x17a4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
label_17a4c8:
    // 0x17a4c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a4c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a4cc:
    // 0x17a4cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a4ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a4d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a4d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a4d4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17a4d4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a4d8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17a4d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17a4dc: 0x3e00008  jr          $ra
    ctx->pc = 0x17A4DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A4E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A4DCu;
            // 0x17a4e0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A4E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

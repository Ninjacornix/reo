#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D800
// Address: 0x13d800 - 0x13d8b0
void sub_0013D800_0x13d800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D800_0x13d800");
#endif

    switch (ctx->pc) {
        case 0x13d854u: goto label_13d854;
        case 0x13d880u: goto label_13d880;
        default: break;
    }

    ctx->pc = 0x13d800u;

    // 0x13d800: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13d800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13d804: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13d804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d808: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13d808u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d80c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13d80cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d810: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13d810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13d814: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x13d814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d818: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13D818u;
    {
        const bool branch_taken_0x13d818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D818u;
            // 0x13d81c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d818) {
            ctx->pc = 0x13D840u;
            goto label_13d840;
        }
    }
    ctx->pc = 0x13D820u;
    // 0x13d820: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d820u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d824: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d824u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d828: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d828u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d82c: 0x2484d498  addiu       $a0, $a0, -0x2B68
    ctx->pc = 0x13d82cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956184));
    // 0x13d830: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13d830u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d834: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13D834u;
    ctx->pc = 0x13D838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D834u;
            // 0x13d838: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D83Cu;
    // 0x13d83c: 0x0  nop
    ctx->pc = 0x13d83cu;
    // NOP
label_13d840:
    // 0x13d840: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13d840u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13d844: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x13d844u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x13d848: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x13d848u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13d84c: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x13D84Cu;
    SET_GPR_U32(ctx, 31, 0x13D854u);
    ctx->pc = 0x13D850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D84Cu;
            // 0x13d850: 0x24510038  addiu       $s1, $v0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D854u; }
        if (ctx->pc != 0x13D854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D854u; }
        if (ctx->pc != 0x13D854u) { return; }
    }
    ctx->pc = 0x13D854u;
label_13d854:
    // 0x13d854: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x13d854u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d858: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x13d858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x13d85c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13D85Cu;
    {
        const bool branch_taken_0x13d85c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x13D860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D85Cu;
            // 0x13d860: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d85c) {
            ctx->pc = 0x13D870u;
            goto label_13d870;
        }
    }
    ctx->pc = 0x13D864u;
    // 0x13d864: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x13d864u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x13d868: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x13D868u;
    {
        const bool branch_taken_0x13d868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D86Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D868u;
            // 0x13d86c: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d868) {
            ctx->pc = 0x13D89Cu;
            goto label_13d89c;
        }
    }
    ctx->pc = 0x13D870u;
label_13d870:
    // 0x13d870: 0x14640005  bne         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13D870u;
    {
        const bool branch_taken_0x13d870 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x13D874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D870u;
            // 0x13d874: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d870) {
            ctx->pc = 0x13D888u;
            goto label_13d888;
        }
    }
    ctx->pc = 0x13D878u;
    // 0x13d878: 0xc04c182  jal         func_130608
    ctx->pc = 0x13D878u;
    SET_GPR_U32(ctx, 31, 0x13D880u);
    ctx->pc = 0x13D87Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D878u;
            // 0x13d87c: 0x8e040028  lw          $a0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D880u; }
        if (ctx->pc != 0x13D880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D880u; }
        if (ctx->pc != 0x13D880u) { return; }
    }
    ctx->pc = 0x13D880u;
label_13d880:
    // 0x13d880: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13D880u;
    {
        const bool branch_taken_0x13d880 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D880u;
            // 0x13d884: 0xae22001c  sw          $v0, 0x1C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d880) {
            ctx->pc = 0x13D89Cu;
            goto label_13d89c;
        }
    }
    ctx->pc = 0x13D888u;
label_13d888:
    // 0x13d888: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13D888u;
    {
        const bool branch_taken_0x13d888 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d888) {
            ctx->pc = 0x13D88Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D888u;
            // 0x13d88c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D8A0u;
            goto label_13d8a0;
        }
    }
    ctx->pc = 0x13D890u;
    // 0x13d890: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x13d890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13d894: 0xae240018  sw          $a0, 0x18($s1)
    ctx->pc = 0x13d894u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 4));
    // 0x13d898: 0xae22001c  sw          $v0, 0x1C($s1)
    ctx->pc = 0x13d898u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 2));
label_13d89c:
    // 0x13d89c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d89cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13d8a0:
    // 0x13d8a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d8a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d8a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13d8a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d8a8: 0x3e00008  jr          $ra
    ctx->pc = 0x13D8A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D8ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D8A8u;
            // 0x13d8ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D840u: goto label_13d840;
            case 0x13D854u: goto label_13d854;
            case 0x13D870u: goto label_13d870;
            case 0x13D880u: goto label_13d880;
            case 0x13D888u: goto label_13d888;
            case 0x13D89Cu: goto label_13d89c;
            case 0x13D8A0u: goto label_13d8a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D8B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

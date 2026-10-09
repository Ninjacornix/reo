#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AA00
// Address: 0x13aa00 - 0x13aab0
void sub_0013AA00_0x13aa00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AA00_0x13aa00");
#endif

    switch (ctx->pc) {
        case 0x13aa28u: goto label_13aa28;
        case 0x13aa64u: goto label_13aa64;
        case 0x13aa94u: goto label_13aa94;
        default: break;
    }

    ctx->pc = 0x13aa00u;

    // 0x13aa00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13aa00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13aa04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13aa04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13aa08: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13aa08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aa0c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13aa0cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13aa10: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13aa10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13aa14: 0x2484cd00  addiu       $a0, $a0, -0x3300
    ctx->pc = 0x13aa14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954240));
    // 0x13aa18: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x13aa18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aa1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13aa1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13aa20: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x13AA20u;
    SET_GPR_U32(ctx, 31, 0x13AA28u);
    ctx->pc = 0x13AA24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA20u;
            // 0x13aa24: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AA28u; }
        if (ctx->pc != 0x13AA28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AA28u; }
        if (ctx->pc != 0x13AA28u) { return; }
    }
    ctx->pc = 0x13AA28u;
label_13aa28:
    // 0x13aa28: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13aa28u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13aa2c: 0x2463d8d0  addiu       $v1, $v1, -0x2730
    ctx->pc = 0x13aa2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294957264));
    // 0x13aa30: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x13AA30u;
    {
        const bool branch_taken_0x13aa30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA30u;
            // 0x13aa34: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13aa30) {
            ctx->pc = 0x13AA70u;
            goto label_13aa70;
        }
    }
    ctx->pc = 0x13AA38u;
    // 0x13aa38: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x13aa38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x13aa3c: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13aa3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13aa40: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x13aa40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x13aa44: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13aa44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13aa48: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13aa48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x13aa4c: 0x50640012  beql        $v1, $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x13AA4Cu;
    {
        const bool branch_taken_0x13aa4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x13aa4c) {
            ctx->pc = 0x13AA50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA4Cu;
            // 0x13aa50: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AA98u;
            goto label_13aa98;
        }
    }
    ctx->pc = 0x13AA54u;
    // 0x13aa54: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13aa54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13aa58: 0x2405002e  addiu       $a1, $zero, 0x2E
    ctx->pc = 0x13aa58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x13aa5c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13AA5Cu;
    SET_GPR_U32(ctx, 31, 0x13AA64u);
    ctx->pc = 0x13AA60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA5Cu;
            // 0x13aa60: 0x2484cd08  addiu       $a0, $a0, -0x32F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AA64u; }
        if (ctx->pc != 0x13AA64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AA64u; }
        if (ctx->pc != 0x13AA64u) { return; }
    }
    ctx->pc = 0x13AA64u;
label_13aa64:
    // 0x13aa64: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x13AA64u;
    {
        const bool branch_taken_0x13aa64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA64u;
            // 0x13aa68: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13aa64) {
            ctx->pc = 0x13AA98u;
            goto label_13aa98;
        }
    }
    ctx->pc = 0x13AA6Cu;
    // 0x13aa6c: 0x0  nop
    ctx->pc = 0x13aa6cu;
    // NOP
label_13aa70:
    // 0x13aa70: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13aa70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13aa74: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x13aa74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x13aa78: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13aa78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13aa7c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13AA7Cu;
    {
        const bool branch_taken_0x13aa7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AA80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA7Cu;
            // 0x13aa80: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13aa7c) {
            ctx->pc = 0x13AA94u;
            goto label_13aa94;
        }
    }
    ctx->pc = 0x13AA84u;
    // 0x13aa84: 0x8c670004  lw          $a3, 0x4($v1)
    ctx->pc = 0x13aa84u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x13aa88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13aa88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aa8c: 0xc04ea44  jal         func_13A910
    ctx->pc = 0x13AA8Cu;
    SET_GPR_U32(ctx, 31, 0x13AA94u);
    ctx->pc = 0x13AA90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AA8Cu;
            // 0x13aa90: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A910u;
    if (runtime->hasFunction(0x13A910u)) {
        auto targetFn = runtime->lookupFunction(0x13A910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AA94u; }
        if (ctx->pc != 0x13AA94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A910_0x13a910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AA94u; }
        if (ctx->pc != 0x13AA94u) { return; }
    }
    ctx->pc = 0x13AA94u;
label_13aa94:
    // 0x13aa94: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13aa94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13aa98:
    // 0x13aa98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13aa98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13aa9c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13aa9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13aaa0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13aaa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13aaa4: 0x3e00008  jr          $ra
    ctx->pc = 0x13AAA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AAA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AAA4u;
            // 0x13aaa8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AA28u: goto label_13aa28;
            case 0x13AA64u: goto label_13aa64;
            case 0x13AA70u: goto label_13aa70;
            case 0x13AA94u: goto label_13aa94;
            case 0x13AA98u: goto label_13aa98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AAACu;
    // 0x13aaac: 0x0  nop
    ctx->pc = 0x13aaacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

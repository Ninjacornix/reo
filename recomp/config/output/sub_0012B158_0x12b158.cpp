#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B158
// Address: 0x12b158 - 0x12b1b8
void sub_0012B158_0x12b158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B158_0x12b158");
#endif

    switch (ctx->pc) {
        case 0x12b17cu: goto label_12b17c;
        case 0x12b19cu: goto label_12b19c;
        default: break;
    }

    ctx->pc = 0x12b158u;

    // 0x12b158: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12b158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12b15c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b160: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12b160u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b164: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12b164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12b168: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x12b168u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b16c: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x12B16Cu;
    {
        const bool branch_taken_0x12b16c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B16Cu;
            // 0x12b170: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b16c) {
            ctx->pc = 0x12B1A0u;
            goto label_12b1a0;
        }
    }
    ctx->pc = 0x12B174u;
    // 0x12b174: 0xc045148  jal         func_114520
    ctx->pc = 0x12B174u;
    SET_GPR_U32(ctx, 31, 0x12B17Cu);
    ctx->pc = 0x12B178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B174u;
            // 0x12b178: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B17Cu; }
        if (ctx->pc != 0x12B17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B17Cu; }
        if (ctx->pc != 0x12B17Cu) { return; }
    }
    ctx->pc = 0x12B17Cu;
label_12b17c:
    // 0x12b17c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x12b17cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b180: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x12b180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12b184: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x12B184u;
    {
        const bool branch_taken_0x12b184 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x12B188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B184u;
            // 0x12b188: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b184) {
            ctx->pc = 0x12B1A0u;
            goto label_12b1a0;
        }
    }
    ctx->pc = 0x12B18Cu;
    // 0x12b18c: 0x50640005  beql        $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12B18Cu;
    {
        const bool branch_taken_0x12b18c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x12b18c) {
            ctx->pc = 0x12B190u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12B18Cu;
            // 0x12b190: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12B1A4u;
            goto label_12b1a4;
        }
    }
    ctx->pc = 0x12B194u;
    // 0x12b194: 0xc045164  jal         func_114590
    ctx->pc = 0x12B194u;
    SET_GPR_U32(ctx, 31, 0x12B19Cu);
    ctx->pc = 0x12B198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B194u;
            // 0x12b198: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114590u;
    if (runtime->hasFunction(0x114590u)) {
        auto targetFn = runtime->lookupFunction(0x114590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B19Cu; }
        if (ctx->pc != 0x12B19Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114590_0x114590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B19Cu; }
        if (ctx->pc != 0x12B19Cu) { return; }
    }
    ctx->pc = 0x12B19Cu;
label_12b19c:
    // 0x12b19c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12b19cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_12b1a0:
    // 0x12b1a0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x12b1a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12b1a4:
    // 0x12b1a4: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b1a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b1a8: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12b1a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b1ac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12b1acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12b1b0: 0x3e00008  jr          $ra
    ctx->pc = 0x12B1B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B1B0u;
            // 0x12b1b4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B17Cu: goto label_12b17c;
            case 0x12B19Cu: goto label_12b19c;
            case 0x12B1A0u: goto label_12b1a0;
            case 0x12B1A4u: goto label_12b1a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B1B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

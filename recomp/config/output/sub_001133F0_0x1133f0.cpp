#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001133F0
// Address: 0x1133f0 - 0x113488
void sub_001133F0_0x1133f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001133F0_0x1133f0");
#endif

    switch (ctx->pc) {
        case 0x113404u: goto label_113404;
        case 0x11341cu: goto label_11341c;
        case 0x113458u: goto label_113458;
        default: break;
    }

    ctx->pc = 0x1133f0u;

    // 0x1133f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1133f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1133f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1133f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1133f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1133f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1133fc: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x1133FCu;
    SET_GPR_U32(ctx, 31, 0x113404u);
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113404u; }
        if (ctx->pc != 0x113404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113404u; }
        if (ctx->pc != 0x113404u) { return; }
    }
    ctx->pc = 0x113404u;
label_113404:
    // 0x113404: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x113404u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113408: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x113408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11340c: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x11340Cu;
    {
        const bool branch_taken_0x11340c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11340c) {
            ctx->pc = 0x113450u;
            goto label_113450;
        }
    }
    ctx->pc = 0x113414u;
    // 0x113414: 0xc0452ac  jal         func_114AB0
    ctx->pc = 0x113414u;
    SET_GPR_U32(ctx, 31, 0x11341Cu);
    ctx->pc = 0x114AB0u;
    if (runtime->hasFunction(0x114AB0u)) {
        auto targetFn = runtime->lookupFunction(0x114AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11341Cu; }
        if (ctx->pc != 0x11341Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114AB0_0x114ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11341Cu; }
        if (ctx->pc != 0x11341Cu) { return; }
    }
    ctx->pc = 0x11341Cu;
label_11341c:
    // 0x11341c: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x11341cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x113420: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x113420u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x113424: 0x14620014  bne         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x113424u;
    {
        const bool branch_taken_0x113424 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x113428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113424u;
            // 0x113428: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113424) {
            ctx->pc = 0x113478u;
            goto label_113478;
        }
    }
    ctx->pc = 0x11342Cu;
    // 0x11342c: 0x3c031200  lui         $v1, 0x1200
    ctx->pc = 0x11342cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4608 << 16));
    // 0x113430: 0x34631000  ori         $v1, $v1, 0x1000
    ctx->pc = 0x113430u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4096);
    // 0x113434: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x113434u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113438: 0x2137a  dsrl        $v0, $v0, 13
    ctx->pc = 0x113438u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 13);
    // 0x11343c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11343cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x113440: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x113440u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x113444: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x113444u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x113448: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x113448u;
    {
        const bool branch_taken_0x113448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11344Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113448u;
            // 0x11344c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113448) {
            ctx->pc = 0x11347Cu;
            goto label_11347c;
        }
    }
    ctx->pc = 0x113450u;
label_113450:
    // 0x113450: 0xc0452d0  jal         func_114B40
    ctx->pc = 0x113450u;
    SET_GPR_U32(ctx, 31, 0x113458u);
    ctx->pc = 0x114B40u;
    if (runtime->hasFunction(0x114B40u)) {
        auto targetFn = runtime->lookupFunction(0x114B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113458u; }
        if (ctx->pc != 0x113458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114B40_0x114b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113458u; }
        if (ctx->pc != 0x113458u) { return; }
    }
    ctx->pc = 0x113458u;
label_113458:
    // 0x113458: 0x2137b  dsra        $v0, $v0, 13
    ctx->pc = 0x113458u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> 13);
    // 0x11345c: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x11345cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x113460: 0x30440001  andi        $a0, $v0, 0x1
    ctx->pc = 0x113460u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x113464: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x113464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x113468: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x113468u;
    {
        const bool branch_taken_0x113468 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x11346Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113468u;
            // 0x11346c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113468) {
            ctx->pc = 0x113478u;
            goto label_113478;
        }
    }
    ctx->pc = 0x113470u;
    // 0x113470: 0x4103c  dsll32      $v0, $a0, 0
    ctx->pc = 0x113470u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x113474: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x113474u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
label_113478:
    // 0x113478: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x113478u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11347c:
    // 0x11347c: 0x3e00008  jr          $ra
    ctx->pc = 0x11347Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11347Cu;
            // 0x113480: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113404u: goto label_113404;
            case 0x11341Cu: goto label_11341c;
            case 0x113450u: goto label_113450;
            case 0x113458u: goto label_113458;
            case 0x113478u: goto label_113478;
            case 0x11347Cu: goto label_11347c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113484u;
    // 0x113484: 0x0  nop
    ctx->pc = 0x113484u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129350
// Address: 0x129350 - 0x129408
void sub_00129350_0x129350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129350_0x129350");
#endif

    switch (ctx->pc) {
        case 0x12937cu: goto label_12937c;
        case 0x129398u: goto label_129398;
        case 0x1293b0u: goto label_1293b0;
        case 0x1293b8u: goto label_1293b8;
        case 0x1293c8u: goto label_1293c8;
        default: break;
    }

    ctx->pc = 0x129350u;

    // 0x129350: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x129354: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x129354u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129358: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x129358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12935c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12935cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129360: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x129360u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129364: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x129364u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x129368: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x129368u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12936c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12936cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129370: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x129370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x129374: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129374u;
    SET_GPR_U32(ctx, 31, 0x12937Cu);
    ctx->pc = 0x129378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129374u;
            // 0x129378: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12937Cu; }
        if (ctx->pc != 0x12937Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12937Cu; }
        if (ctx->pc != 0x12937Cu) { return; }
    }
    ctx->pc = 0x12937Cu;
label_12937c:
    // 0x12937c: 0x1220001c  beqz        $s1, . + 4 + (0x1C << 2)
    ctx->pc = 0x12937Cu;
    {
        const bool branch_taken_0x12937c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x129380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12937Cu;
            // 0x129380: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12937c) {
            ctx->pc = 0x1293F0u;
            goto label_1293f0;
        }
    }
    ctx->pc = 0x129384u;
    // 0x129384: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x129384u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x129388: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x129388u;
    {
        const bool branch_taken_0x129388 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x129388) {
            ctx->pc = 0x12938Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129388u;
            // 0x12938c: 0x8e300004  lw          $s0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12939Cu;
            goto label_12939c;
        }
    }
    ctx->pc = 0x129390u;
    // 0x129390: 0xc04a5f8  jal         func_1297E0
    ctx->pc = 0x129390u;
    SET_GPR_U32(ctx, 31, 0x129398u);
    ctx->pc = 0x129394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129390u;
            // 0x129394: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297E0u;
    if (runtime->hasFunction(0x1297E0u)) {
        auto targetFn = runtime->lookupFunction(0x1297E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129398u; }
        if (ctx->pc != 0x129398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297E0_0x1297e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129398u; }
        if (ctx->pc != 0x129398u) { return; }
    }
    ctx->pc = 0x129398u;
label_129398:
    // 0x129398: 0x8e300004  lw          $s0, 0x4($s1)
    ctx->pc = 0x129398u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_12939c:
    // 0x12939c: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x12939Cu;
    {
        const bool branch_taken_0x12939c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1293A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12939Cu;
            // 0x1293a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12939c) {
            ctx->pc = 0x1293B8u;
            goto label_1293b8;
        }
    }
    ctx->pc = 0x1293A4u;
    // 0x1293a4: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x1293a4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1293a8: 0xc04c158  jal         func_130560
    ctx->pc = 0x1293A8u;
    SET_GPR_U32(ctx, 31, 0x1293B0u);
    ctx->pc = 0x1293ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1293A8u;
            // 0x1293ac: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130560u;
    if (runtime->hasFunction(0x130560u)) {
        auto targetFn = runtime->lookupFunction(0x130560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1293B0u; }
        if (ctx->pc != 0x1293B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130560_0x130560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1293B0u; }
        if (ctx->pc != 0x1293B0u) { return; }
    }
    ctx->pc = 0x1293B0u;
label_1293b0:
    // 0x1293b0: 0xc04c108  jal         func_130420
    ctx->pc = 0x1293B0u;
    SET_GPR_U32(ctx, 31, 0x1293B8u);
    ctx->pc = 0x1293B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1293B0u;
            // 0x1293b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130420u;
    if (runtime->hasFunction(0x130420u)) {
        auto targetFn = runtime->lookupFunction(0x130420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1293B8u; }
        if (ctx->pc != 0x1293B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130420_0x130420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1293B8u; }
        if (ctx->pc != 0x1293B8u) { return; }
    }
    ctx->pc = 0x1293B8u;
label_1293b8:
    // 0x1293b8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1293b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1293bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1293bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1293c0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1293C0u;
    SET_GPR_U32(ctx, 31, 0x1293C8u);
    ctx->pc = 0x1293C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1293C0u;
            // 0x1293c4: 0x24060044  addiu       $a2, $zero, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1293C8u; }
        if (ctx->pc != 0x1293C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1293C8u; }
        if (ctx->pc != 0x1293C8u) { return; }
    }
    ctx->pc = 0x1293C8u;
label_1293c8:
    // 0x1293c8: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1293c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1293cc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1293ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1293d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1293d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1293d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1293d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1293d8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1293d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1293dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1293dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1293e0: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1293e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1293e4: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x1293e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1293e8: 0x804a13e  j           func_1284F8
    ctx->pc = 0x1293E8u;
    ctx->pc = 0x1293ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1293E8u;
            // 0x1293ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001284F8_0x1284f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1293F0u;
label_1293f0:
    // 0x1293f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1293f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1293f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1293f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1293f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1293f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1293fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1293FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1293FCu;
            // 0x129400: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12937Cu: goto label_12937c;
            case 0x129398u: goto label_129398;
            case 0x12939Cu: goto label_12939c;
            case 0x1293B0u: goto label_1293b0;
            case 0x1293B8u: goto label_1293b8;
            case 0x1293C8u: goto label_1293c8;
            case 0x1293F0u: goto label_1293f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129404u;
    // 0x129404: 0x0  nop
    ctx->pc = 0x129404u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113010
// Address: 0x113010 - 0x1130f8
void sub_00113010_0x113010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113010_0x113010");
#endif

    switch (ctx->pc) {
        case 0x113048u: goto label_113048;
        case 0x1130bcu: goto label_1130bc;
        default: break;
    }

    ctx->pc = 0x113010u;

    // 0x113010: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x113010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x113014: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113014u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113018: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x113018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11301c: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x11301cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x113020: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x113020u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113024: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x113024u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113028: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x113028u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x11302c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11302Cu;
    {
        const bool branch_taken_0x11302c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x113030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11302Cu;
            // 0x113030: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11302c) {
            ctx->pc = 0x113064u;
            goto label_113064;
        }
    }
    ctx->pc = 0x113034u;
    // 0x113034: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113034u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113038: 0x3c050100  lui         $a1, 0x100
    ctx->pc = 0x113038u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x11303c: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x11303cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x113040: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x113040u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113044: 0x0  nop
    ctx->pc = 0x113044u;
    // NOP
label_113048:
    // 0x113048: 0xa2102b  sltu        $v0, $a1, $v0
    ctx->pc = 0x113048u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11304c: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x11304Cu;
    {
        const bool branch_taken_0x11304c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11304Cu;
            // 0x113050: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11304c) {
            ctx->pc = 0x1130B0u;
            goto label_1130b0;
        }
    }
    ctx->pc = 0x113054u;
    // 0x113054: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x113054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113058: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x113058u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x11305c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11305Cu;
    {
        const bool branch_taken_0x11305c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11305Cu;
            // 0x113060: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11305c) {
            ctx->pc = 0x113048u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113048;
        }
    }
    ctx->pc = 0x113064u;
label_113064:
    // 0x113064: 0xdcc20000  ld          $v0, 0x0($a2)
    ctx->pc = 0x113064u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113068: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113068u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x11306c: 0x3463a020  ori         $v1, $v1, 0xA020
    ctx->pc = 0x11306cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40992);
    // 0x113070: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x113070u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x113074: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x113074u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x113078: 0xc42824  and         $a1, $a2, $a0
    ctx->pc = 0x113078u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & GPR_U64(ctx, 4));
    // 0x11307c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11307cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x113080: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x113080u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x113084: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x113084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x113088: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x113088u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x11308c: 0x14a4000d  bne         $a1, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x11308Cu;
    {
        const bool branch_taken_0x11308c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x113090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11308Cu;
            // 0x113090: 0x3c020fff  lui         $v0, 0xFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11308c) {
            ctx->pc = 0x1130C4u;
            goto label_1130c4;
        }
    }
    ctx->pc = 0x113094u;
    // 0x113094: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113094u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113098: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x113098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11309c: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11309cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1130a0: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x1130a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x1130a4: 0x3463a010  ori         $v1, $v1, 0xA010
    ctx->pc = 0x1130a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40976);
    // 0x1130a8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1130A8u;
    {
        const bool branch_taken_0x1130a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1130ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1130A8u;
            // 0x1130ac: 0x441025  or          $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1130a8) {
            ctx->pc = 0x1130D4u;
            goto label_1130d4;
        }
    }
    ctx->pc = 0x1130B0u;
label_1130b0:
    // 0x1130b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1130b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1130b4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1130B4u;
    SET_GPR_U32(ctx, 31, 0x1130BCu);
    ctx->pc = 0x1130B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1130B4u;
            // 0x1130b8: 0x24848600  addiu       $a0, $a0, -0x7A00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1130BCu; }
        if (ctx->pc != 0x1130BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1130BCu; }
        if (ctx->pc != 0x1130BCu) { return; }
    }
    ctx->pc = 0x1130BCu;
label_1130bc:
    // 0x1130bc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1130BCu;
    {
        const bool branch_taken_0x1130bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1130C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1130BCu;
            // 0x1130c0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1130bc) {
            ctx->pc = 0x1130ECu;
            goto label_1130ec;
        }
    }
    ctx->pc = 0x1130C4u;
label_1130c4:
    // 0x1130c4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1130c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1130c8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1130c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1130cc: 0x3463a010  ori         $v1, $v1, 0xA010
    ctx->pc = 0x1130ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40976);
    // 0x1130d0: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x1130d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
label_1130d4:
    // 0x1130d4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1130d4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x1130d8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1130d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1130dc: 0x24040101  addiu       $a0, $zero, 0x101
    ctx->pc = 0x1130dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x1130e0: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x1130e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x1130e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1130e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1130e8: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1130e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_1130ec:
    // 0x1130ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1130ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1130f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1130F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1130F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1130F0u;
            // 0x1130f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113048u: goto label_113048;
            case 0x113064u: goto label_113064;
            case 0x1130B0u: goto label_1130b0;
            case 0x1130BCu: goto label_1130bc;
            case 0x1130C4u: goto label_1130c4;
            case 0x1130D4u: goto label_1130d4;
            case 0x1130ECu: goto label_1130ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1130F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F42C0
// Address: 0x1f42c0 - 0x1f43c0
void sub_001F42C0_0x1f42c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F42C0_0x1f42c0");
#endif

    switch (ctx->pc) {
        case 0x1f42dcu: goto label_1f42dc;
        default: break;
    }

    ctx->pc = 0x1f42c0u;

    // 0x1f42c0: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x1f42c0u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42c4: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x1f42c4u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f42c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42cc: 0x2409002b  addiu       $t1, $zero, 0x2B
    ctx->pc = 0x1f42ccu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x1f42d0: 0x2408002f  addiu       $t0, $zero, 0x2F
    ctx->pc = 0x1f42d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1f42d4: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1F42D4u;
    {
        const bool branch_taken_0x1f42d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F42D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42D4u;
            // 0x1f42d8: 0x240a003d  addiu       $t2, $zero, 0x3D (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f42d4) {
            ctx->pc = 0x1F43A4u;
            goto label_1f43a4;
        }
    }
    ctx->pc = 0x1F42DCu;
label_1f42dc:
    // 0x1f42dc: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x1f42dcu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f42e0: 0x116a0023  beq         $t3, $t2, . + 4 + (0x23 << 2)
    ctx->pc = 0x1F42E0u;
    {
        const bool branch_taken_0x1f42e0 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 10));
        ctx->pc = 0x1F42E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42E0u;
            // 0x1f42e4: 0x29830008  slti        $v1, $t4, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 12) < (int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f42e0) {
            ctx->pc = 0x1F4370u;
            goto label_1f4370;
        }
    }
    ctx->pc = 0x1F42E8u;
    // 0x1f42e8: 0x2d630041  sltiu       $v1, $t3, 0x41
    ctx->pc = 0x1f42e8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)65) ? 1 : 0);
    // 0x1f42ec: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F42ECu;
    {
        const bool branch_taken_0x1f42ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F42F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42ECu;
            // 0x1f42f0: 0x2d630061  sltiu       $v1, $t3, 0x61 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)97) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f42ec) {
            ctx->pc = 0x1F4308u;
            goto label_1f4308;
        }
    }
    ctx->pc = 0x1F42F4u;
    // 0x1f42f4: 0x2d61005b  sltiu       $at, $t3, 0x5B
    ctx->pc = 0x1f42f4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)91) ? 1 : 0);
    // 0x1f42f8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F42F8u;
    {
        const bool branch_taken_0x1f42f8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f42f8) {
            ctx->pc = 0x1F4308u;
            goto label_1f4308;
        }
    }
    ctx->pc = 0x1F4300u;
    // 0x1f4300: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1F4300u;
    {
        const bool branch_taken_0x1f4300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4300u;
            // 0x1f4304: 0x256bffbf  addiu       $t3, $t3, -0x41 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967231));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4300) {
            ctx->pc = 0x1F4360u;
            goto label_1f4360;
        }
    }
    ctx->pc = 0x1F4308u;
label_1f4308:
    // 0x1f4308: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F4308u;
    {
        const bool branch_taken_0x1f4308 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F430Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4308u;
            // 0x1f430c: 0x2d61007b  sltiu       $at, $t3, 0x7B (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)123) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4308) {
            ctx->pc = 0x1F4320u;
            goto label_1f4320;
        }
    }
    ctx->pc = 0x1F4310u;
    // 0x1f4310: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F4310u;
    {
        const bool branch_taken_0x1f4310 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4310u;
            // 0x1f4314: 0x2d630030  sltiu       $v1, $t3, 0x30 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)48) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4310) {
            ctx->pc = 0x1F4324u;
            goto label_1f4324;
        }
    }
    ctx->pc = 0x1F4318u;
    // 0x1f4318: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1F4318u;
    {
        const bool branch_taken_0x1f4318 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F431Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4318u;
            // 0x1f431c: 0x256bffb9  addiu       $t3, $t3, -0x47 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967225));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4318) {
            ctx->pc = 0x1F4360u;
            goto label_1f4360;
        }
    }
    ctx->pc = 0x1F4320u;
label_1f4320:
    // 0x1f4320: 0x2d630030  sltiu       $v1, $t3, 0x30
    ctx->pc = 0x1f4320u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)48) ? 1 : 0);
label_1f4324:
    // 0x1f4324: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F4324u;
    {
        const bool branch_taken_0x1f4324 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4324u;
            // 0x1f4328: 0x2d61003a  sltiu       $at, $t3, 0x3A (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)58) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4324) {
            ctx->pc = 0x1F433Cu;
            goto label_1f433c;
        }
    }
    ctx->pc = 0x1F432Cu;
    // 0x1f432c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F432Cu;
    {
        const bool branch_taken_0x1f432c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f432c) {
            ctx->pc = 0x1F433Cu;
            goto label_1f433c;
        }
    }
    ctx->pc = 0x1F4334u;
    // 0x1f4334: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F4334u;
    {
        const bool branch_taken_0x1f4334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4334u;
            // 0x1f4338: 0x256b0004  addiu       $t3, $t3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4334) {
            ctx->pc = 0x1F4360u;
            goto label_1f4360;
        }
    }
    ctx->pc = 0x1F433Cu;
label_1f433c:
    // 0x1f433c: 0x15690003  bne         $t3, $t1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F433Cu;
    {
        const bool branch_taken_0x1f433c = (GPR_U64(ctx, 11) != GPR_U64(ctx, 9));
        if (branch_taken_0x1f433c) {
            ctx->pc = 0x1F434Cu;
            goto label_1f434c;
        }
    }
    ctx->pc = 0x1F4344u;
    // 0x1f4344: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F4344u;
    {
        const bool branch_taken_0x1f4344 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4344u;
            // 0x1f4348: 0x240b003e  addiu       $t3, $zero, 0x3E (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4344) {
            ctx->pc = 0x1F4360u;
            goto label_1f4360;
        }
    }
    ctx->pc = 0x1F434Cu;
label_1f434c:
    // 0x1f434c: 0x15680003  bne         $t3, $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F434Cu;
    {
        const bool branch_taken_0x1f434c = (GPR_U64(ctx, 11) != GPR_U64(ctx, 8));
        if (branch_taken_0x1f434c) {
            ctx->pc = 0x1F435Cu;
            goto label_1f435c;
        }
    }
    ctx->pc = 0x1F4354u;
    // 0x1f4354: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F4354u;
    {
        const bool branch_taken_0x1f4354 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4354u;
            // 0x1f4358: 0x240b003f  addiu       $t3, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4354) {
            ctx->pc = 0x1F4360u;
            goto label_1f4360;
        }
    }
    ctx->pc = 0x1F435Cu;
label_1f435c:
    // 0x1f435c: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x1f435cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1f4360:
    // 0x1f4360: 0xd1980  sll         $v1, $t5, 6
    ctx->pc = 0x1f4360u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 13), 6));
    // 0x1f4364: 0x258c0006  addiu       $t4, $t4, 0x6
    ctx->pc = 0x1f4364u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 6));
    // 0x1f4368: 0x6b6825  or          $t5, $v1, $t3
    ctx->pc = 0x1f4368u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 3) | GPR_U64(ctx, 11));
    // 0x1f436c: 0x29830008  slti        $v1, $t4, 0x8
    ctx->pc = 0x1f436cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 12) < (int64_t)(int32_t)8) ? 1 : 0);
label_1f4370:
    // 0x1f4370: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1f4370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1f4374: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1F4374u;
    {
        const bool branch_taken_0x1f4374 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4374u;
            // 0x1f4378: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4374) {
            ctx->pc = 0x1F43A4u;
            goto label_1f43a4;
        }
    }
    ctx->pc = 0x1F437Cu;
    // 0x1f437c: 0x2583fff8  addiu       $v1, $t4, -0x8
    ctx->pc = 0x1f437cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967288));
    // 0x1f4380: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x1f4380u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1f4384: 0x6d1806  srlv        $v1, $t5, $v1
    ctx->pc = 0x1f4384u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 13), GPR_U32(ctx, 3) & 0x1F));
    // 0x1f4388: 0x258cfff8  addiu       $t4, $t4, -0x8
    ctx->pc = 0x1f4388u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967288));
    // 0x1f438c: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x1f438cu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f4390: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f4390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f4394: 0x1ce00003  bgtz        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4394u;
    {
        const bool branch_taken_0x1f4394 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1F4398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4394u;
            // 0x1f4398: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4394) {
            ctx->pc = 0x1F43A4u;
            goto label_1f43a4;
        }
    }
    ctx->pc = 0x1F439Cu;
    // 0x1f439c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1F439Cu;
    {
        const bool branch_taken_0x1f439c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F43A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F439Cu;
            // 0x1f43a0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f439c) {
            ctx->pc = 0x1F43ACu;
            goto label_1f43ac;
        }
    }
    ctx->pc = 0x1F43A4u;
label_1f43a4:
    // 0x1f43a4: 0x1cc0ffcd  bgtz        $a2, . + 4 + (-0x33 << 2)
    ctx->pc = 0x1F43A4u;
    {
        const bool branch_taken_0x1f43a4 = (GPR_S64(ctx, 6) > 0);
        if (branch_taken_0x1f43a4) {
            ctx->pc = 0x1F42DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f42dc;
        }
    }
    ctx->pc = 0x1F43ACu;
label_1f43ac:
    // 0x1f43ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1F43ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F42DCu: goto label_1f42dc;
            case 0x1F4308u: goto label_1f4308;
            case 0x1F4320u: goto label_1f4320;
            case 0x1F4324u: goto label_1f4324;
            case 0x1F433Cu: goto label_1f433c;
            case 0x1F434Cu: goto label_1f434c;
            case 0x1F435Cu: goto label_1f435c;
            case 0x1F4360u: goto label_1f4360;
            case 0x1F4370u: goto label_1f4370;
            case 0x1F43A4u: goto label_1f43a4;
            case 0x1F43ACu: goto label_1f43ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F43B4u;
    // 0x1f43b4: 0x0  nop
    ctx->pc = 0x1f43b4u;
    // NOP
    // 0x1f43b8: 0x0  nop
    ctx->pc = 0x1f43b8u;
    // NOP
    // 0x1f43bc: 0x0  nop
    ctx->pc = 0x1f43bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

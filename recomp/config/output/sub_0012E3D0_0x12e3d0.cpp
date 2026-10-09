#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E3D0
// Address: 0x12e3d0 - 0x12e4b8
void sub_0012E3D0_0x12e3d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E3D0_0x12e3d0");
#endif

    switch (ctx->pc) {
        case 0x12e3f8u: goto label_12e3f8;
        default: break;
    }

    ctx->pc = 0x12e3d0u;

    // 0x12e3d0: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x12e3d0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x12e3d4: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x12e3d4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e3d8: 0x14a0000f  bnez        $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x12E3D8u;
    {
        const bool branch_taken_0x12e3d8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E3D8u;
            // 0x12e3dc: 0x64c03  sra         $t1, $a2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 6), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e3d8) {
            ctx->pc = 0x12E418u;
            goto label_12e418;
        }
    }
    ctx->pc = 0x12E3E0u;
    // 0x12e3e0: 0x8d030014  lw          $v1, 0x14($t0)
    ctx->pc = 0x12e3e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 20)));
    // 0x12e3e4: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x12e3e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12e3e8: 0x5040000b  beql        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x12E3E8u;
    {
        const bool branch_taken_0x12e3e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12e3e8) {
            ctx->pc = 0x12E3ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12E3E8u;
            // 0x12e3ec: 0xad000078  sw          $zero, 0x78($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 120), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12E418u;
            goto label_12e418;
        }
    }
    ctx->pc = 0x12E3F0u;
    // 0x12e3f0: 0x25020018  addiu       $v0, $t0, 0x18
    ctx->pc = 0x12e3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 24));
    // 0x12e3f4: 0x0  nop
    ctx->pc = 0x12e3f4u;
    // NOP
label_12e3f8:
    // 0x12e3f8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x12e3f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x12e3fc: 0xa4400000  sh          $zero, 0x0($v0)
    ctx->pc = 0x12e3fcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x12e400: 0x0  nop
    ctx->pc = 0x12e400u;
    // NOP
    // 0x12e404: 0x0  nop
    ctx->pc = 0x12e404u;
    // NOP
    // 0x12e408: 0x0  nop
    ctx->pc = 0x12e408u;
    // NOP
    // 0x12e40c: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12E40Cu;
    {
        const bool branch_taken_0x12e40c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E40Cu;
            // 0x12e410: 0x24420002  addiu       $v0, $v0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e40c) {
            ctx->pc = 0x12E3F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e3f8;
        }
    }
    ctx->pc = 0x12E414u;
    // 0x12e414: 0xad000078  sw          $zero, 0x78($t0)
    ctx->pc = 0x12e414u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 120), GPR_U32(ctx, 0));
label_12e418:
    // 0x12e418: 0x11000024  beqz        $t0, . + 4 + (0x24 << 2)
    ctx->pc = 0x12E418u;
    {
        const bool branch_taken_0x12e418 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        if (branch_taken_0x12e418) {
            ctx->pc = 0x12E4ACu;
            goto label_12e4ac;
        }
    }
    ctx->pc = 0x12E420u;
    // 0x12e420: 0x85020004  lh          $v0, 0x4($t0)
    ctx->pc = 0x12e420u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x12e424: 0x52040  sll         $a0, $a1, 1
    ctx->pc = 0x12e424u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x12e428: 0x85070008  lh          $a3, 0x8($t0)
    ctx->pc = 0x12e428u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x12e42c: 0x24057fff  addiu       $a1, $zero, 0x7FFF
    ctx->pc = 0x12e42cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x12e430: 0x8506000a  lh          $a2, 0xA($t0)
    ctx->pc = 0x12e430u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 10)));
    // 0x12e434: 0x882021  addu        $a0, $a0, $t0
    ctx->pc = 0x12e434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x12e438: 0x85030006  lh          $v1, 0x6($t0)
    ctx->pc = 0x12e438u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 6)));
    // 0x12e43c: 0x471018  mult        $v0, $v0, $a3
    ctx->pc = 0x12e43cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x12e440: 0x661818  mult        $v1, $v1, $a2
    ctx->pc = 0x12e440u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x12e444: 0x21303  sra         $v0, $v0, 12
    ctx->pc = 0x12e444u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 12));
    // 0x12e448: 0x1221023  subu        $v0, $t1, $v0
    ctx->pc = 0x12e448u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x12e44c: 0x31b03  sra         $v1, $v1, 12
    ctx->pc = 0x12e44cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 12));
    // 0x12e450: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x12e450u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12e454: 0xa6282a  slt         $a1, $a1, $a2
    ctx->pc = 0x12e454u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x12e458: 0x14a00007  bnez        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x12E458u;
    {
        const bool branch_taken_0x12e458 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E458u;
            // 0x12e45c: 0x24840018  addiu       $a0, $a0, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e458) {
            ctx->pc = 0x12E478u;
            goto label_12e478;
        }
    }
    ctx->pc = 0x12E460u;
    // 0x12e460: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x12e460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x12e464: 0x28c38000  slti        $v1, $a2, -0x8000
    ctx->pc = 0x12e464u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x12e468: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12e468u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e46c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12E46Cu;
    {
        const bool branch_taken_0x12e46c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E46Cu;
            // 0x12e470: 0xc3280a  movz        $a1, $a2, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e46c) {
            ctx->pc = 0x12E47Cu;
            goto label_12e47c;
        }
    }
    ctx->pc = 0x12E474u;
    // 0x12e474: 0x0  nop
    ctx->pc = 0x12e474u;
    // NOP
label_12e478:
    // 0x12e478: 0x24057fff  addiu       $a1, $zero, 0x7FFF
    ctx->pc = 0x12e478u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
label_12e47c:
    // 0x12e47c: 0x51400  sll         $v0, $a1, 16
    ctx->pc = 0x12e47cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x12e480: 0x8d030078  lw          $v1, 0x78($t0)
    ctx->pc = 0x12e480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 120)));
    // 0x12e484: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x12e484u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x12e488: 0x4420001  bltzl       $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x12E488u;
    {
        const bool branch_taken_0x12e488 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x12e488) {
            ctx->pc = 0x12E48Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12E488u;
            // 0x12e48c: 0x21023  negu        $v0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12E490u;
            goto label_12e490;
        }
    }
    ctx->pc = 0x12E490u;
label_12e490:
    // 0x12e490: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x12e490u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12e494: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x12E494u;
    {
        const bool branch_taken_0x12e494 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E494u;
            // 0x12e498: 0xa4850000  sh          $a1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e494) {
            ctx->pc = 0x12E4A0u;
            goto label_12e4a0;
        }
    }
    ctx->pc = 0x12E49Cu;
    // 0x12e49c: 0xad020078  sw          $v0, 0x78($t0)
    ctx->pc = 0x12e49cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 120), GPR_U32(ctx, 2));
label_12e4a0:
    // 0x12e4a0: 0x95020008  lhu         $v0, 0x8($t0)
    ctx->pc = 0x12e4a0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x12e4a4: 0xa5090008  sh          $t1, 0x8($t0)
    ctx->pc = 0x12e4a4u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 8), (uint16_t)GPR_U32(ctx, 9));
    // 0x12e4a8: 0xa502000a  sh          $v0, 0xA($t0)
    ctx->pc = 0x12e4a8u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 10), (uint16_t)GPR_U32(ctx, 2));
label_12e4ac:
    // 0x12e4ac: 0x3e00008  jr          $ra
    ctx->pc = 0x12E4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E3F8u: goto label_12e3f8;
            case 0x12E418u: goto label_12e418;
            case 0x12E478u: goto label_12e478;
            case 0x12E47Cu: goto label_12e47c;
            case 0x12E490u: goto label_12e490;
            case 0x12E4A0u: goto label_12e4a0;
            case 0x12E4ACu: goto label_12e4ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E4B4u;
    // 0x12e4b4: 0x0  nop
    ctx->pc = 0x12e4b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

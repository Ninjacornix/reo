#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001284F8
// Address: 0x1284f8 - 0x1285a8
void sub_001284F8_0x1284f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001284F8_0x1284f8");
#endif

    ctx->pc = 0x1284f8u;

    // 0x1284f8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1284f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1284fc: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x1284fcu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128500: 0x244cd228  addiu       $t4, $v0, -0x2DD8
    ctx->pc = 0x128500u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955560));
    // 0x128504: 0xa0682d  daddu       $t5, $a1, $zero
    ctx->pc = 0x128504u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128508: 0x8d830000  lw          $v1, 0x0($t4)
    ctx->pc = 0x128508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x12850c: 0xa4840  sll         $t1, $t2, 1
    ctx->pc = 0x12850cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
    // 0x128510: 0x3c0b0021  lui         $t3, 0x21
    ctx->pc = 0x128510u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)33 << 16));
    // 0x128514: 0x256bd208  addiu       $t3, $t3, -0x2DF8
    ctx->pc = 0x128514u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294955528));
    // 0x128518: 0x1695821  addu        $t3, $t3, $t1
    ctx->pc = 0x128518u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 9)));
    // 0x12851c: 0x2465000f  addiu       $a1, $v1, 0xF
    ctx->pc = 0x12851cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x128520: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x128520u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x128524: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x128524u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128528: 0xa4100b  movn        $v0, $a1, $a0
    ctx->pc = 0x128528u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x12852c: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x12852cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x128530: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x128530u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x128534: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x128534u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x128538: 0x32100  sll         $a0, $v1, 4
    ctx->pc = 0x128538u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x12853c: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x12853cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x128540: 0x24a5d108  addiu       $a1, $a1, -0x2EF8
    ctx->pc = 0x128540u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955272));
    // 0x128544: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x128544u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x128548: 0x15a00007  bnez        $t5, . + 4 + (0x7 << 2)
    ctx->pc = 0x128548u;
    {
        const bool branch_taken_0x128548 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        ctx->pc = 0x12854Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128548u;
            // 0x12854c: 0xad830000  sw          $v1, 0x0($t4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 12), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128548) {
            ctx->pc = 0x128568u;
            goto label_128568;
        }
    }
    ctx->pc = 0x128550u;
    // 0x128550: 0x95620000  lhu         $v0, 0x0($t3)
    ctx->pc = 0x128550u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x128554: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128554u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x128558: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x128558u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12855c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x12855Cu;
    {
        const bool branch_taken_0x12855c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12855Cu;
            // 0x128560: 0xa5620000  sh          $v0, 0x0($t3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 11), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12855c) {
            ctx->pc = 0x128570u;
            goto label_128570;
        }
    }
    ctx->pc = 0x128564u;
    // 0x128564: 0x0  nop
    ctx->pc = 0x128564u;
    // NOP
label_128568:
    // 0x128568: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128568u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12856c: 0xa4840  sll         $t1, $t2, 1
    ctx->pc = 0x12856cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
label_128570:
    // 0x128570: 0x8d830000  lw          $v1, 0x0($t4)
    ctx->pc = 0x128570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x128574: 0x2484d208  addiu       $a0, $a0, -0x2DF8
    ctx->pc = 0x128574u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955528));
    // 0x128578: 0xa0aa0000  sb          $t2, 0x0($a1)
    ctx->pc = 0x128578u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 10));
    // 0x12857c: 0x1242021  addu        $a0, $t1, $a0
    ctx->pc = 0x12857cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
    // 0x128580: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x128580u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x128584: 0xa0ad0001  sb          $t5, 0x1($a1)
    ctx->pc = 0x128584u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 13));
    // 0x128588: 0xaca8000c  sw          $t0, 0xC($a1)
    ctx->pc = 0x128588u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 8));
    // 0x12858c: 0xaca60004  sw          $a2, 0x4($a1)
    ctx->pc = 0x12858cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 6));
    // 0x128590: 0xaca70008  sw          $a3, 0x8($a1)
    ctx->pc = 0x128590u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 7));
    // 0x128594: 0xad830000  sw          $v1, 0x0($t4)
    ctx->pc = 0x128594u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 0), GPR_U32(ctx, 3));
    // 0x128598: 0x94820000  lhu         $v0, 0x0($a0)
    ctx->pc = 0x128598u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12859c: 0x3e00008  jr          $ra
    ctx->pc = 0x12859Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1285A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12859Cu;
            // 0x1285a0: 0xa4a20002  sh          $v0, 0x2($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128568u: goto label_128568;
            case 0x128570u: goto label_128570;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1285A4u;
    // 0x1285a4: 0x0  nop
    ctx->pc = 0x1285a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

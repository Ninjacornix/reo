#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001004D8
// Address: 0x1004d8 - 0x100590
void sub_001004D8_0x1004d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001004D8_0x1004d8");
#endif

    switch (ctx->pc) {
        case 0x100508u: goto label_100508;
        case 0x100560u: goto label_100560;
        default: break;
    }

    ctx->pc = 0x1004d8u;

    // 0x1004d8: 0x3c052000  lui         $a1, 0x2000
    ctx->pc = 0x1004d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)8192 << 16));
    // 0x1004dc: 0x853825  or          $a3, $a0, $a1
    ctx->pc = 0x1004dcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1004e0: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1004e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1004e4: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1004E4u;
    {
        const bool branch_taken_0x1004e4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1004E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1004E4u;
            // 0x1004e8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1004e4) {
            ctx->pc = 0x100538u;
            goto label_100538;
        }
    }
    ctx->pc = 0x1004ECu;
    // 0x1004ec: 0x8ce90008  lw          $t1, 0x8($a3)
    ctx->pc = 0x1004ecu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1004f0: 0x18400011  blez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1004F0u;
    {
        const bool branch_taken_0x1004f0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1004F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1004F0u;
            // 0x1004f4: 0x1255025  or          $t2, $t1, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 9) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1004f0) {
            ctx->pc = 0x100538u;
            goto label_100538;
        }
    }
    ctx->pc = 0x1004F8u;
    // 0x1004f8: 0x24e80010  addiu       $t0, $a3, 0x10
    ctx->pc = 0x1004f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x1004fc: 0x3c0b0020  lui         $t3, 0x20
    ctx->pc = 0x1004fcu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32 << 16));
    // 0x100500: 0x1061021  addu        $v0, $t0, $a2
    ctx->pc = 0x100500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x100504: 0x0  nop
    ctx->pc = 0x100504u;
    // NOP
label_100508:
    // 0x100508: 0x1462821  addu        $a1, $t2, $a2
    ctx->pc = 0x100508u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x10050c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x10050cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x100510: 0x1262021  addu        $a0, $t1, $a2
    ctx->pc = 0x100510u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x100514: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x100514u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x100518: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x100518u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x10051c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x10051cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x100520: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x100520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x100524: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x100524u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x100528: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x100528u;
    {
        const bool branch_taken_0x100528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10052Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100528u;
            // 0x10052c: 0x1061021  addu        $v0, $t0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100528) {
            ctx->pc = 0x100508u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100508;
        }
    }
    ctx->pc = 0x100530u;
    // 0x100530: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100530u;
    {
        const bool branch_taken_0x100530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100530u;
            // 0x100534: 0x8ce30004  lw          $v1, 0x4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100530) {
            ctx->pc = 0x100540u;
            goto label_100540;
        }
    }
    ctx->pc = 0x100538u;
label_100538:
    // 0x100538: 0x3c0b0020  lui         $t3, 0x20
    ctx->pc = 0x100538u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32 << 16));
    // 0x10053c: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x10053cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_100540:
    // 0x100540: 0x18600011  blez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x100540u;
    {
        const bool branch_taken_0x100540 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100540u;
            // 0x100544: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100540) {
            ctx->pc = 0x100588u;
            goto label_100588;
        }
    }
    ctx->pc = 0x100548u;
    // 0x100548: 0x8ce9000c  lw          $t1, 0xC($a3)
    ctx->pc = 0x100548u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x10054c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x10054cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100550: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x100550u;
    {
        const bool branch_taken_0x100550 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100550u;
            // 0x100554: 0x1225025  or          $t2, $t1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100550) {
            ctx->pc = 0x100588u;
            goto label_100588;
        }
    }
    ctx->pc = 0x100558u;
    // 0x100558: 0x24e80050  addiu       $t0, $a3, 0x50
    ctx->pc = 0x100558u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 80));
    // 0x10055c: 0x1061021  addu        $v0, $t0, $a2
    ctx->pc = 0x10055cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
label_100560:
    // 0x100560: 0x1462821  addu        $a1, $t2, $a2
    ctx->pc = 0x100560u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x100564: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x100564u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x100568: 0x1262021  addu        $a0, $t1, $a2
    ctx->pc = 0x100568u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x10056c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10056cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x100570: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x100570u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x100574: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x100574u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x100578: 0x8ce20004  lw          $v0, 0x4($a3)
    ctx->pc = 0x100578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x10057c: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x10057cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x100580: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x100580u;
    {
        const bool branch_taken_0x100580 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100580u;
            // 0x100584: 0x1061021  addu        $v0, $t0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100580) {
            ctx->pc = 0x100560u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100560;
        }
    }
    ctx->pc = 0x100588u;
label_100588:
    // 0x100588: 0x80400a6  j           func_100298
    ctx->pc = 0x100588u;
    ctx->pc = 0x10058Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100588u;
            // 0x10058c: 0x25647958  addiu       $a0, $t3, 0x7958 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 11), 31064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100298u;
    if (runtime->hasFunction(0x100298u)) {
        auto targetFn = runtime->lookupFunction(0x100298u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00100298_0x100298(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x100590u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

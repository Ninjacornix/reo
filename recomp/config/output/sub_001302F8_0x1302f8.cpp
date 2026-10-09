#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001302F8
// Address: 0x1302f8 - 0x1303d8
void sub_001302F8_0x1302f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001302F8_0x1302f8");
#endif

    switch (ctx->pc) {
        case 0x130368u: goto label_130368;
        case 0x1303c0u: goto label_1303c0;
        default: break;
    }

    ctx->pc = 0x1302f8u;

    // 0x1302f8: 0x3c0d0022  lui         $t5, 0x22
    ctx->pc = 0x1302f8u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)34 << 16));
    // 0x1302fc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1302fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130300: 0x8da9a8ac  lw          $t1, -0x5754($t5)
    ctx->pc = 0x130300u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944940)));
    // 0x130304: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x130304u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130308: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13030c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x13030cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130310: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130314: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x130314u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130318: 0xc0582d  daddu       $t3, $a2, $zero
    ctx->pc = 0x130318u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13031c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x13031cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130320: 0x1920001f  blez        $t1, . + 4 + (0x1F << 2)
    ctx->pc = 0x130320u;
    {
        const bool branch_taken_0x130320 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x130324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130320u;
            // 0x130324: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130320) {
            ctx->pc = 0x1303A0u;
            goto label_1303a0;
        }
    }
    ctx->pc = 0x130328u;
    // 0x130328: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13032c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13032cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x130330: 0x2447a8a8  addiu       $a3, $v0, -0x5758
    ctx->pc = 0x130330u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944936));
    // 0x130334: 0x2484a8c0  addiu       $a0, $a0, -0x5740
    ctx->pc = 0x130334u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944960));
    // 0x130338: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x130338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x13033c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x13033cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x130340: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x130340u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x130344: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x130344u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x130348: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x130348u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13034c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x13034cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x130350: 0x448021  addu        $s0, $v0, $a0
    ctx->pc = 0x130350u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x130354: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x130354u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130358: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x130358u;
    {
        const bool branch_taken_0x130358 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130358u;
            // 0x13035c: 0x8da3a8ac  lw          $v1, -0x5754($t5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944940)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130358) {
            ctx->pc = 0x1303A4u;
            goto label_1303a4;
        }
    }
    ctx->pc = 0x130360u;
    // 0x130360: 0x120302d  daddu       $a2, $t1, $zero
    ctx->pc = 0x130360u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130364: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x130364u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_130368:
    // 0x130368: 0xa6102a  slt         $v0, $a1, $a2
    ctx->pc = 0x130368u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13036c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13036Cu;
    {
        const bool branch_taken_0x13036c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x130370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13036Cu;
            // 0x130370: 0x8da3a8ac  lw          $v1, -0x5754($t5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944940)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13036c) {
            ctx->pc = 0x1303A4u;
            goto label_1303a4;
        }
    }
    ctx->pc = 0x130374u;
    // 0x130374: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x130374u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x130378: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x130378u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x13037c: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x13037cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x130380: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x130380u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x130384: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x130384u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x130388: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x130388u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13038c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x13038cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x130390: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x130390u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x130394: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x130394u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130398: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x130398u;
    {
        const bool branch_taken_0x130398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x130398) {
            ctx->pc = 0x13039Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130398u;
            // 0x13039c: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130368u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130368;
        }
    }
    ctx->pc = 0x1303A0u;
label_1303a0:
    // 0x1303a0: 0x8da3a8ac  lw          $v1, -0x5754($t5)
    ctx->pc = 0x1303a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944940)));
label_1303a4:
    // 0x1303a4: 0x10a30007  beq         $a1, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1303A4u;
    {
        const bool branch_taken_0x1303a4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1303A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1303A4u;
            // 0x1303a8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1303a4) {
            ctx->pc = 0x1303C4u;
            goto label_1303c4;
        }
    }
    ctx->pc = 0x1303ACu;
    // 0x1303ac: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1303acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303b0: 0x140302d  daddu       $a2, $t2, $zero
    ctx->pc = 0x1303b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303b4: 0x160382d  daddu       $a3, $t3, $zero
    ctx->pc = 0x1303b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303b8: 0xc04c042  jal         func_130108
    ctx->pc = 0x1303B8u;
    SET_GPR_U32(ctx, 31, 0x1303C0u);
    ctx->pc = 0x1303BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1303B8u;
            // 0x1303bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130108u;
    if (runtime->hasFunction(0x130108u)) {
        auto targetFn = runtime->lookupFunction(0x130108u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1303C0u; }
        if (ctx->pc != 0x1303C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130108_0x130108(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1303C0u; }
        if (ctx->pc != 0x1303C0u) { return; }
    }
    ctx->pc = 0x1303C0u;
label_1303c0:
    // 0x1303c0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1303c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1303c4:
    // 0x1303c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1303c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1303c8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1303c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1303cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1303CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1303D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1303CCu;
            // 0x1303d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130368u: goto label_130368;
            case 0x1303A0u: goto label_1303a0;
            case 0x1303A4u: goto label_1303a4;
            case 0x1303C0u: goto label_1303c0;
            case 0x1303C4u: goto label_1303c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1303D4u;
    // 0x1303d4: 0x0  nop
    ctx->pc = 0x1303d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

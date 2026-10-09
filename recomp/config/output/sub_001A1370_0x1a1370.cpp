#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1370
// Address: 0x1a1370 - 0x1a13ec
void sub_001A1370_0x1a1370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1370_0x1a1370");
#endif

    switch (ctx->pc) {
        case 0x1a13dcu: goto label_1a13dc;
        default: break;
    }

    ctx->pc = 0x1a1370u;

    // 0x1a1370: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a1370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a1374: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a1374u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a1378: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a1378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a137c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a137cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1380: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1a1380u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a1384: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1384u;
    {
        const bool branch_taken_0x1a1384 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1384u;
            // 0x1a1388: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1384) {
            ctx->pc = 0x1A1394u;
            goto label_1a1394;
        }
    }
    ctx->pc = 0x1A138Cu;
    // 0x1a138c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A138Cu;
    {
        const bool branch_taken_0x1a138c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A138Cu;
            // 0x1a1390: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a138c) {
            ctx->pc = 0x1A13E4u;
            goto label_1a13e4;
        }
    }
    ctx->pc = 0x1A1394u;
label_1a1394:
    // 0x1a1394: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a1394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1398: 0x51900  sll         $v1, $a1, 4
    ctx->pc = 0x1a1398u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1a139c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a139cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a13a0: 0x8c460004  lw          $a2, 0x4($v0)
    ctx->pc = 0x1a13a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a13a4: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A13A4u;
    {
        const bool branch_taken_0x1a13a4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A13A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A13A4u;
            // 0x1a13a8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a13a4) {
            ctx->pc = 0x1A13B4u;
            goto label_1a13b4;
        }
    }
    ctx->pc = 0x1A13ACu;
    // 0x1a13ac: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A13ACu;
    {
        const bool branch_taken_0x1a13ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a13ac) {
            ctx->pc = 0x1A13E0u;
            goto label_1a13e0;
        }
    }
    ctx->pc = 0x1A13B4u;
label_1a13b4:
    // 0x1a13b4: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x1a13b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1a13b8: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x1a13b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1a13bc: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x1a13bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
    // 0x1a13c0: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a13c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a13c4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a13c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a13c8: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x1a13c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x1a13cc: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a13ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a13d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a13d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a13d4: 0xc0685e8  jal         func_1A17A0
    ctx->pc = 0x1A13D4u;
    SET_GPR_U32(ctx, 31, 0x1A13DCu);
    ctx->pc = 0x1A13D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A13D4u;
            // 0x1a13d8: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A17A0u;
    if (runtime->hasFunction(0x1A17A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A17A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A13DCu; }
        if (ctx->pc != 0x1A13DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A17A0_0x1a17a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A13DCu; }
        if (ctx->pc != 0x1A13DCu) { return; }
    }
    ctx->pc = 0x1A13DCu;
label_1a13dc:
    // 0x1a13dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a13dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a13e0:
    // 0x1a13e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a13e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a13e4:
    // 0x1a13e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A13E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A13E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A13E4u;
            // 0x1a13e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1394u: goto label_1a1394;
            case 0x1A13B4u: goto label_1a13b4;
            case 0x1A13DCu: goto label_1a13dc;
            case 0x1A13E0u: goto label_1a13e0;
            case 0x1A13E4u: goto label_1a13e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A13ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

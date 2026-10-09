#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D61B8
// Address: 0x1d61b8 - 0x1d6220
void sub_001D61B8_0x1d61b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D61B8_0x1d61b8");
#endif

    ctx->pc = 0x1d61b8u;

    // 0x1d61b8: 0x24020038  addiu       $v0, $zero, 0x38
    ctx->pc = 0x1d61b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1d61bc: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d61bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d61c0: 0x822018  mult        $a0, $a0, $v0
    ctx->pc = 0x1d61c0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1d61c4: 0x8c662844  lw          $a2, 0x2844($v1)
    ctx->pc = 0x1d61c4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10308)));
    // 0x1d61c8: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x1d61c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1d61cc: 0x24c70010  addiu       $a3, $a2, 0x10
    ctx->pc = 0x1d61ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x1d61d0: 0x8ce20024  lw          $v0, 0x24($a3)
    ctx->pc = 0x1d61d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x1d61d4: 0x5c400003  bgtzl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D61D4u;
    {
        const bool branch_taken_0x1d61d4 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d61d4) {
            ctx->pc = 0x1D61D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D61D4u;
            // 0x1d61d8: 0x8cc40030  lw          $a0, 0x30($a2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D61E4u;
            goto label_1d61e4;
        }
    }
    ctx->pc = 0x1D61DCu;
    // 0x1d61dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D61DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D61E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D61DCu;
            // 0x1d61e0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D61E4u: goto label_1d61e4;
            case 0x1D620Cu: goto label_1d620c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D61E4u;
label_1d61e4:
    // 0x1d61e4: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1d61e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1d61e8: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1d61e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1d61ec: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1d61ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1d61f0: 0x94430022  lhu         $v1, 0x22($v0)
    ctx->pc = 0x1d61f0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 34)));
    // 0x1d61f4: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1d61f4u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d61f8: 0xacc40030  sw          $a0, 0x30($a2)
    ctx->pc = 0x1d61f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 4));
    // 0x1d61fc: 0x8ce20020  lw          $v0, 0x20($a3)
    ctx->pc = 0x1d61fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x1d6200: 0x28420004  slti        $v0, $v0, 0x4
    ctx->pc = 0x1d6200u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d6204: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1D6204u;
    {
        const bool branch_taken_0x1d6204 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6204) {
            ctx->pc = 0x1D6208u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6204u;
            // 0x1d6208: 0xace00020  sw          $zero, 0x20($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D620Cu;
            goto label_1d620c;
        }
    }
    ctx->pc = 0x1D620Cu;
label_1d620c:
    // 0x1d620c: 0x8ce30024  lw          $v1, 0x24($a3)
    ctx->pc = 0x1d620cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x1d6210: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d6210u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6214: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1d6214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1d6218: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6218u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D621Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6218u;
            // 0x1d621c: 0xace30024  sw          $v1, 0x24($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 36), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D61E4u: goto label_1d61e4;
            case 0x1D620Cu: goto label_1d620c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6220u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192C80
// Address: 0x192c80 - 0x192d10
void sub_00192C80_0x192c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192C80_0x192c80");
#endif

    switch (ctx->pc) {
        case 0x192c88u: goto label_192c88;
        case 0x192cd8u: goto label_192cd8;
        case 0x192ce8u: goto label_192ce8;
        default: break;
    }

    ctx->pc = 0x192c80u;

    // 0x192c80: 0x30c3ffff  andi        $v1, $a2, 0xFFFF
    ctx->pc = 0x192c80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x192c84: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x192c84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_192c88:
    // 0x192c88: 0x948200c6  lhu         $v0, 0xC6($a0)
    ctx->pc = 0x192c88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 198)));
    // 0x192c8c: 0x1443000b  bne         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x192C8Cu;
    {
        const bool branch_taken_0x192c8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x192c8c) {
            ctx->pc = 0x192CBCu;
            goto label_192cbc;
        }
    }
    ctx->pc = 0x192C94u;
    // 0x192c94: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x192c94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x192c98: 0x8c22fe40  lw          $v0, -0x1C0($at)
    ctx->pc = 0x192c98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966848)));
    // 0x192c9c: 0xac8200d4  sw          $v0, 0xD4($a0)
    ctx->pc = 0x192c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 2));
    // 0x192ca0: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x192ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x192ca4: 0xac8200d8  sw          $v0, 0xD8($a0)
    ctx->pc = 0x192ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 2));
    // 0x192ca8: 0x8c8200d0  lw          $v0, 0xD0($a0)
    ctx->pc = 0x192ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 208)));
    // 0x192cac: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192CACu;
    {
        const bool branch_taken_0x192cac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x192CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192CACu;
            // 0x192cb0: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192cac) {
            ctx->pc = 0x192CBCu;
            goto label_192cbc;
        }
    }
    ctx->pc = 0x192CB4u;
    // 0x192cb4: 0x1000fff4  b           . + 4 + (-0xC << 2)
    ctx->pc = 0x192CB4u;
    {
        const bool branch_taken_0x192cb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192CB4u;
            // 0x192cb8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192cb4) {
            ctx->pc = 0x192C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192c88;
        }
    }
    ctx->pc = 0x192CBCu;
label_192cbc:
    // 0x192cbc: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192cc0: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x192CC0u;
    {
        const bool branch_taken_0x192cc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192cc0) {
            ctx->pc = 0x192CFCu;
            goto label_192cfc;
        }
    }
    ctx->pc = 0x192CC8u;
    // 0x192cc8: 0x1086000c  beq         $a0, $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x192CC8u;
    {
        const bool branch_taken_0x192cc8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        if (branch_taken_0x192cc8) {
            ctx->pc = 0x192CFCu;
            goto label_192cfc;
        }
    }
    ctx->pc = 0x192CD0u;
    // 0x192cd0: 0x1000ffed  b           . + 4 + (-0x13 << 2)
    ctx->pc = 0x192CD0u;
    {
        const bool branch_taken_0x192cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192CD0u;
            // 0x192cd4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192cd0) {
            ctx->pc = 0x192C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192c88;
        }
    }
    ctx->pc = 0x192CD8u;
label_192cd8:
    // 0x192cd8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x192cd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192cdc: 0x944200c6  lhu         $v0, 0xC6($v0)
    ctx->pc = 0x192cdcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 198)));
    // 0x192ce0: 0x1043ffe9  beq         $v0, $v1, . + 4 + (-0x17 << 2)
    ctx->pc = 0x192CE0u;
    {
        const bool branch_taken_0x192ce0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x192ce0) {
            ctx->pc = 0x192C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192c88;
        }
    }
    ctx->pc = 0x192CE8u;
label_192ce8:
    // 0x192ce8: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192cec: 0x0  nop
    ctx->pc = 0x192cecu;
    // NOP
    // 0x192cf0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192CF0u;
    {
        const bool branch_taken_0x192cf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x192cf0) {
            ctx->pc = 0x192CD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192cd8;
        }
    }
    ctx->pc = 0x192CF8u;
    // 0x192cf8: 0x8c8400c8  lw          $a0, 0xC8($a0)
    ctx->pc = 0x192cf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 200)));
label_192cfc:
    // 0x192cfc: 0x1486fffa  bne         $a0, $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x192CFCu;
    {
        const bool branch_taken_0x192cfc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        if (branch_taken_0x192cfc) {
            ctx->pc = 0x192CE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ce8;
        }
    }
    ctx->pc = 0x192D04u;
    // 0x192d04: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192d04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192d08: 0x3e00008  jr          $ra
    ctx->pc = 0x192D08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192C88u: goto label_192c88;
            case 0x192CBCu: goto label_192cbc;
            case 0x192CD8u: goto label_192cd8;
            case 0x192CE8u: goto label_192ce8;
            case 0x192CFCu: goto label_192cfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192D10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

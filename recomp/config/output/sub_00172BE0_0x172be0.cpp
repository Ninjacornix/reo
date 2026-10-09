#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172BE0
// Address: 0x172be0 - 0x172c48
void sub_00172BE0_0x172be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172BE0_0x172be0");
#endif

    switch (ctx->pc) {
        case 0x172c34u: goto label_172c34;
        default: break;
    }

    ctx->pc = 0x172be0u;

    // 0x172be0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172be4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x172be4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172be8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x172be8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x172bec: 0x24a609a0  addiu       $a2, $a1, 0x9A0
    ctx->pc = 0x172becu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 2464));
    // 0x172bf0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x172bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172bf4: 0x8cc30038  lw          $v1, 0x38($a2)
    ctx->pc = 0x172bf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 56)));
    // 0x172bf8: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x172BF8u;
    {
        const bool branch_taken_0x172bf8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x172BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172BF8u;
            // 0x172bfc: 0x24a50cc0  addiu       $a1, $a1, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172bf8) {
            ctx->pc = 0x172C38u;
            goto label_172c38;
        }
    }
    ctx->pc = 0x172C00u;
    // 0x172c00: 0x8cc30014  lw          $v1, 0x14($a2)
    ctx->pc = 0x172c00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x172c04: 0x5060000d  beql        $v1, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x172C04u;
    {
        const bool branch_taken_0x172c04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x172c04) {
            ctx->pc = 0x172C08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172C04u;
            // 0x172c08: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172C3Cu;
            goto label_172c3c;
        }
    }
    ctx->pc = 0x172C0Cu;
    // 0x172c0c: 0x8ca3026c  lw          $v1, 0x26C($a1)
    ctx->pc = 0x172c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 620)));
    // 0x172c10: 0x5460000a  bnel        $v1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x172C10u;
    {
        const bool branch_taken_0x172c10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x172c10) {
            ctx->pc = 0x172C14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172C10u;
            // 0x172c14: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172C3Cu;
            goto label_172c3c;
        }
    }
    ctx->pc = 0x172C18u;
    // 0x172c18: 0x8ca30288  lw          $v1, 0x288($a1)
    ctx->pc = 0x172c18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 648)));
    // 0x172c1c: 0x8cc500b4  lw          $a1, 0xB4($a2)
    ctx->pc = 0x172c1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 180)));
    // 0x172c20: 0x65182a  slt         $v1, $v1, $a1
    ctx->pc = 0x172c20u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x172c24: 0x50600005  beql        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x172C24u;
    {
        const bool branch_taken_0x172c24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x172c24) {
            ctx->pc = 0x172C28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172C24u;
            // 0x172c28: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172C3Cu;
            goto label_172c3c;
        }
    }
    ctx->pc = 0x172C2Cu;
    // 0x172c2c: 0xc05cc84  jal         func_173210
    ctx->pc = 0x172C2Cu;
    SET_GPR_U32(ctx, 31, 0x172C34u);
    ctx->pc = 0x173210u;
    if (runtime->hasFunction(0x173210u)) {
        auto targetFn = runtime->lookupFunction(0x173210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172C34u; }
        if (ctx->pc != 0x172C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173210_0x173210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172C34u; }
        if (ctx->pc != 0x172C34u) { return; }
    }
    ctx->pc = 0x172C34u;
label_172c34:
    // 0x172c34: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x172c34u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_172c38:
    // 0x172c38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x172c38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_172c3c:
    // 0x172c3c: 0x3e00008  jr          $ra
    ctx->pc = 0x172C3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172C3Cu;
            // 0x172c40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172C34u: goto label_172c34;
            case 0x172C38u: goto label_172c38;
            case 0x172C3Cu: goto label_172c3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172C44u;
    // 0x172c44: 0x0  nop
    ctx->pc = 0x172c44u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

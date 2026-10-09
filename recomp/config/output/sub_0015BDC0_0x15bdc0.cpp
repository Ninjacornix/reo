#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BDC0
// Address: 0x15bdc0 - 0x15be10
void sub_0015BDC0_0x15bdc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BDC0_0x15bdc0");
#endif

    switch (ctx->pc) {
        case 0x15bdfcu: goto label_15bdfc;
        default: break;
    }

    ctx->pc = 0x15bdc0u;

    // 0x15bdc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15bdc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15bdc4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15bdc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15bdc8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15bdc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15bdcc: 0x1082000c  beq         $a0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x15BDCCu;
    {
        const bool branch_taken_0x15bdcc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15BDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BDCCu;
            // 0x15bdd0: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bdcc) {
            ctx->pc = 0x15BE00u;
            goto label_15be00;
        }
    }
    ctx->pc = 0x15BDD4u;
    // 0x15bdd4: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x15BDD4u;
    {
        const bool branch_taken_0x15bdd4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BDD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BDD4u;
            // 0x15bdd8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bdd4) {
            ctx->pc = 0x15BE00u;
            goto label_15be00;
        }
    }
    ctx->pc = 0x15BDDCu;
    // 0x15bddc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x15bddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15bde0: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15BDE0u;
    {
        const bool branch_taken_0x15bde0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15BDE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BDE0u;
            // 0x15bde4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bde0) {
            ctx->pc = 0x15BE00u;
            goto label_15be00;
        }
    }
    ctx->pc = 0x15BDE8u;
    // 0x15bde8: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15BDE8u;
    {
        const bool branch_taken_0x15bde8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15BDECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BDE8u;
            // 0x15bdec: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bde8) {
            ctx->pc = 0x15BE00u;
            goto label_15be00;
        }
    }
    ctx->pc = 0x15BDF0u;
    // 0x15bdf0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15bdf0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15bdf4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15BDF4u;
    SET_GPR_U32(ctx, 31, 0x15BDFCu);
    ctx->pc = 0x15BDF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BDF4u;
            // 0x15bdf8: 0x2484e6e0  addiu       $a0, $a0, -0x1920 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BDFCu; }
        if (ctx->pc != 0x15BDFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BDFCu; }
        if (ctx->pc != 0x15BDFCu) { return; }
    }
    ctx->pc = 0x15BDFCu;
label_15bdfc:
    // 0x15bdfc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x15bdfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_15be00:
    // 0x15be00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15be00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15be04: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x15be04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15be08: 0x3e00008  jr          $ra
    ctx->pc = 0x15BE08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE08u;
            // 0x15be0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BDFCu: goto label_15bdfc;
            case 0x15BE00u: goto label_15be00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BE10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

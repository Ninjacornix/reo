#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010CDA8
// Address: 0x10cda8 - 0x10cdf8
void sub_0010CDA8_0x10cda8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010CDA8_0x10cda8");
#endif

    switch (ctx->pc) {
        case 0x10cdb8u: goto label_10cdb8;
        default: break;
    }

    ctx->pc = 0x10cda8u;

    // 0x10cda8: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10cda8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10cdac: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x10cdacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cdb0: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x10CDB0u;
    {
        const bool branch_taken_0x10cdb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CDB0u;
            // 0x10cdb4: 0x90830000  lbu         $v1, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cdb0) {
            ctx->pc = 0x10CDECu;
            goto label_10cdec;
        }
    }
    ctx->pc = 0x10CDB8u;
label_10cdb8:
    // 0x10cdb8: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x10cdb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x10cdbc: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10cdbcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10cdc0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10cdc0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10cdc4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10cdc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10cdc8: 0x90637769  lbu         $v1, 0x7769($v1)
    ctx->pc = 0x10cdc8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 30569)));
    // 0x10cdcc: 0x30630002  andi        $v1, $v1, 0x2
    ctx->pc = 0x10cdccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
    // 0x10cdd0: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x10CDD0u;
    {
        const bool branch_taken_0x10cdd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CDD0u;
            // 0x10cdd4: 0x2442ffe0  addiu       $v0, $v0, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cdd0) {
            ctx->pc = 0x10CDDCu;
            goto label_10cddc;
        }
    }
    ctx->pc = 0x10CDD8u;
    // 0x10cdd8: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x10cdd8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
label_10cddc:
    // 0x10cddc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10cddcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10cde0: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x10cde0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10cde4: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x10CDE4u;
    {
        const bool branch_taken_0x10cde4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10CDE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CDE4u;
            // 0x10cde8: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cde4) {
            ctx->pc = 0x10CDB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10cdb8;
        }
    }
    ctx->pc = 0x10CDECu;
label_10cdec:
    // 0x10cdec: 0x3e00008  jr          $ra
    ctx->pc = 0x10CDECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10CDF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CDECu;
            // 0x10cdf0: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10CDB8u: goto label_10cdb8;
            case 0x10CDDCu: goto label_10cddc;
            case 0x10CDECu: goto label_10cdec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10CDF4u;
    // 0x10cdf4: 0x0  nop
    ctx->pc = 0x10cdf4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

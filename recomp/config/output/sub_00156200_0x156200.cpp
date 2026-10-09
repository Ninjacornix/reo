#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00156200
// Address: 0x156200 - 0x1562d0
void sub_00156200_0x156200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00156200_0x156200");
#endif

    switch (ctx->pc) {
        case 0x156218u: goto label_156218;
        case 0x156240u: goto label_156240;
        default: break;
    }

    ctx->pc = 0x156200u;

    // 0x156200: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x156200u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x156204: 0x30c2000f  andi        $v0, $a2, 0xF
    ctx->pc = 0x156204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x156208: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x156208u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x15620c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15620Cu;
    {
        const bool branch_taken_0x15620c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x156210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15620Cu;
            // 0x156210: 0x862021  addu        $a0, $a0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15620c) {
            ctx->pc = 0x156234u;
            goto label_156234;
        }
    }
    ctx->pc = 0x156214u;
    // 0x156214: 0x0  nop
    ctx->pc = 0x156214u;
    // NOP
label_156218:
    // 0x156218: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156218u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x15621c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x15621cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x156220: 0x0  nop
    ctx->pc = 0x156220u;
    // NOP
    // 0x156224: 0x0  nop
    ctx->pc = 0x156224u;
    // NOP
    // 0x156228: 0x0  nop
    ctx->pc = 0x156228u;
    // NOP
    // 0x15622c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x15622Cu;
    {
        const bool branch_taken_0x15622c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x156230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15622Cu;
            // 0x156230: 0xa0850000  sb          $a1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15622c) {
            ctx->pc = 0x156218u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156218;
        }
    }
    ctx->pc = 0x156234u;
label_156234:
    // 0x156234: 0x63102  srl         $a2, $a2, 4
    ctx->pc = 0x156234u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x156238: 0x10c00023  beqz        $a2, . + 4 + (0x23 << 2)
    ctx->pc = 0x156238u;
    {
        const bool branch_taken_0x156238 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x156238) {
            ctx->pc = 0x1562C8u;
            goto label_1562c8;
        }
    }
    ctx->pc = 0x156240u;
label_156240:
    // 0x156240: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156240u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156244: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x156244u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x156248: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156248u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15624c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15624cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156250: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156250u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156254: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156254u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156258: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156258u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15625c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15625cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156260: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156260u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156264: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156264u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156268: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156268u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15626c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15626cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156270: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156270u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156274: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156274u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156278: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156278u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15627c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15627cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156280: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156280u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156284: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156288: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156288u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15628c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15628cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156290: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156290u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156294: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156294u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156298: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156298u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15629c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15629cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562a0: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562a0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562a4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562a8: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562a8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562ac: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562b0: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562b0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562b4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562b8: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562b8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562bc: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562c0: 0x14c0ffdf  bnez        $a2, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1562C0u;
    {
        const bool branch_taken_0x1562c0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1562C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1562C0u;
            // 0x1562c4: 0xa0850000  sb          $a1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1562c0) {
            ctx->pc = 0x156240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156240;
        }
    }
    ctx->pc = 0x1562C8u;
label_1562c8:
    // 0x1562c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1562C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x156218u: goto label_156218;
            case 0x156234u: goto label_156234;
            case 0x156240u: goto label_156240;
            case 0x1562C8u: goto label_1562c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1562D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

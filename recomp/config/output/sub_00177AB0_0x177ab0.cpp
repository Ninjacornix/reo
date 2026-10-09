#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177AB0
// Address: 0x177ab0 - 0x177b10
void sub_00177AB0_0x177ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177AB0_0x177ab0");
#endif

    ctx->pc = 0x177ab0u;

    // 0x177ab0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177ab4: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x177ab4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ab8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x177ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x177abc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x177abcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x177ac0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x177ac0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177ac4: 0x805deb4  j           func_177AD0
    ctx->pc = 0x177AC4u;
    ctx->pc = 0x177AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177AC4u;
            // 0x177ac8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177AD0u;
    goto label_177ad0;
    ctx->pc = 0x177ACCu;
    // 0x177acc: 0x0  nop
    ctx->pc = 0x177accu;
    // NOP
label_177ad0:
    // 0x177ad0: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x177ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x177ad4: 0x51900  sll         $v1, $a1, 4
    ctx->pc = 0x177ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177ad8: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x177ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x177adc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x177adcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x177ae0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177ae4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x177ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x177ae8: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x177ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x177aec: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x177aecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x177af0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x177af0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x177af4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177af4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177af8: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x177af8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x177afc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177afcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177b00: 0xacc71ab4  sw          $a3, 0x1AB4($a2)
    ctx->pc = 0x177b00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 6836), GPR_U32(ctx, 7));
    // 0x177b04: 0x3e00008  jr          $ra
    ctx->pc = 0x177B04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177B04u;
            // 0x177b08: 0xac85118c  sw          $a1, 0x118C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4492), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177AD0u: goto label_177ad0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177B0Cu;
    // 0x177b0c: 0x0  nop
    ctx->pc = 0x177b0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

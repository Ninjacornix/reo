#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001510C0
// Address: 0x1510c0 - 0x151130
void sub_001510C0_0x1510c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001510C0_0x1510c0");
#endif

    ctx->pc = 0x1510c0u;

    // 0x1510c0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1510c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1510c4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1510c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1510c8: 0x8ca20118  lw          $v0, 0x118($a1)
    ctx->pc = 0x1510c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 280)));
    // 0x1510cc: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1510CCu;
    {
        const bool branch_taken_0x1510cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1510cc) {
            ctx->pc = 0x1510D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1510CCu;
            // 0x1510d0: 0x8ca20424  lw          $v0, 0x424($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 1060)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1510E0u;
            goto label_1510e0;
        }
    }
    ctx->pc = 0x1510D4u;
    // 0x1510d4: 0xaca00424  sw          $zero, 0x424($a1)
    ctx->pc = 0x1510d4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 1060), GPR_U32(ctx, 0));
    // 0x1510d8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1510D8u;
    {
        const bool branch_taken_0x1510d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1510DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1510D8u;
            // 0x1510dc: 0xaca00420  sw          $zero, 0x420($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 1056), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1510d8) {
            ctx->pc = 0x151100u;
            goto label_151100;
        }
    }
    ctx->pc = 0x1510E0u;
label_1510e0:
    // 0x1510e0: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x1510e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x1510e4: 0x24440001  addiu       $a0, $v0, 0x1
    ctx->pc = 0x1510e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1510e8: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1510e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1510ec: 0xaca40424  sw          $a0, 0x424($a1)
    ctx->pc = 0x1510ecu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 1060), GPR_U32(ctx, 4));
    // 0x1510f0: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x1510f0u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x1510f4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1510f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1510f8: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1510f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1510fc: 0xaca20420  sw          $v0, 0x420($a1)
    ctx->pc = 0x1510fcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 1056), GPR_U32(ctx, 2));
label_151100:
    // 0x151100: 0x8ca20114  lw          $v0, 0x114($a1)
    ctx->pc = 0x151100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 276)));
    // 0x151104: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x151104u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x151108: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x151108u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x15110c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x15110cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x151110: 0x8c63e460  lw          $v1, -0x1BA0($v1)
    ctx->pc = 0x151110u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294960224)));
    // 0x151114: 0xaca3036c  sw          $v1, 0x36C($a1)
    ctx->pc = 0x151114u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 876), GPR_U32(ctx, 3));
    // 0x151118: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x151118u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15111c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x15111cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x151120: 0x8c84e470  lw          $a0, -0x1B90($a0)
    ctx->pc = 0x151120u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294960240)));
    // 0x151124: 0x3e00008  jr          $ra
    ctx->pc = 0x151124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x151128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151124u;
            // 0x151128: 0xaca4037c  sw          $a0, 0x37C($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 892), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1510E0u: goto label_1510e0;
            case 0x151100u: goto label_151100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15112Cu;
    // 0x15112c: 0x0  nop
    ctx->pc = 0x15112cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7C7C
// Address: 0x1e7c7c - 0x1e7e40
void sub_001E7C7C_0x1e7c7c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7C7C_0x1e7c7c");
#endif

    switch (ctx->pc) {
        case 0x1e7cccu: goto label_1e7ccc;
        case 0x1e7de4u: goto label_1e7de4;
        default: break;
    }

    ctx->pc = 0x1e7c7cu;

    // 0x1e7c7c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e7c7cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e7c80: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e7c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e7c84: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e7c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e7c88: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7c88u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7c8c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e7c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e7c90: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7c90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7c94: 0x2442001f  addiu       $v0, $v0, 0x1F
    ctx->pc = 0x1e7c94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x1e7c98: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e7c98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e7c9c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e7c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7ca0: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E7CA0u;
    {
        const bool branch_taken_0x1e7ca0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e7ca0) {
            ctx->pc = 0x1E7CB4u;
            goto label_1e7cb4;
        }
    }
    ctx->pc = 0x1E7CA8u;
    // 0x1e7ca8: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e7ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7cac: 0x2463001f  addiu       $v1, $v1, 0x1F
    ctx->pc = 0x1e7cacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 31));
    // 0x1e7cb0: 0xafc30014  sw          $v1, 0x14($fp)
    ctx->pc = 0x1e7cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
label_1e7cb4:
    // 0x1e7cb4: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e7cb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7cb8: 0x31143  sra         $v0, $v1, 5
    ctx->pc = 0x1e7cb8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 5));
    // 0x1e7cbc: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x1e7cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1e7cc0: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e7cc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1e7cc4: 0xafc00010  sw          $zero, 0x10($fp)
    ctx->pc = 0x1e7cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1e7cc8: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e7cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1e7ccc:
    // 0x1e7ccc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7cd0: 0x3403cb1f  ori         $v1, $zero, 0xCB1F
    ctx->pc = 0x1e7cd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)51999);
    // 0x1e7cd4: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1e7cd4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1e7cd8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7CD8u;
    {
        const bool branch_taken_0x1e7cd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7cd8) {
            ctx->pc = 0x1E7CE8u;
            goto label_1e7ce8;
        }
    }
    ctx->pc = 0x1E7CE0u;
    // 0x1e7ce0: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E7CE0u;
    {
        const bool branch_taken_0x1e7ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7ce0) {
            ctx->pc = 0x1E7E04u;
            goto label_1e7e04;
        }
    }
    ctx->pc = 0x1E7CE8u;
label_1e7ce8:
    // 0x1e7ce8: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1e7ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1e7cec: 0x24638ca0  addiu       $v1, $v1, -0x7360
    ctx->pc = 0x1e7cecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937760));
    // 0x1e7cf0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7cf4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7cf8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7cfc: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7d00: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e7d00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7d04: 0x3c02fafa  lui         $v0, 0xFAFA
    ctx->pc = 0x1e7d04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64250 << 16));
    // 0x1e7d08: 0x3442fafa  ori         $v0, $v0, 0xFAFA
    ctx->pc = 0x1e7d08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64250);
    // 0x1e7d0c: 0x1462002d  bne         $v1, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1E7D0Cu;
    {
        const bool branch_taken_0x1e7d0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e7d0c) {
            ctx->pc = 0x1E7DC4u;
            goto label_1e7dc4;
        }
    }
    ctx->pc = 0x1E7D14u;
    // 0x1e7d14: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7d14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7d18: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e7d18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e7d1c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e7d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e7d20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7d24: 0x24430008  addiu       $v1, $v0, 0x8
    ctx->pc = 0x1e7d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7d28: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e7d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7d2c: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x1e7d2cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1e7d30: 0x1440002c  bnez        $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1E7D30u;
    {
        const bool branch_taken_0x1e7d30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e7d30) {
            ctx->pc = 0x1E7DE4u;
            goto label_1e7de4;
        }
    }
    ctx->pc = 0x1E7D38u;
    // 0x1e7d38: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e7d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7d3c: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1e7d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1e7d40: 0x24428ca8  addiu       $v0, $v0, -0x7358
    ctx->pc = 0x1e7d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937768));
    // 0x1e7d44: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7d48: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e7d48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e7d4c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e7d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7d50: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7d50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7d54: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1e7d54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1e7d58: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e7d58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7d5c: 0x3c02fafa  lui         $v0, 0xFAFA
    ctx->pc = 0x1e7d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64250 << 16));
    // 0x1e7d60: 0x3442fafa  ori         $v0, $v0, 0xFAFA
    ctx->pc = 0x1e7d60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64250);
    // 0x1e7d64: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e7d64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e7d68: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e7d68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7d6c: 0x3c02fbfb  lui         $v0, 0xFBFB
    ctx->pc = 0x1e7d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64507 << 16));
    // 0x1e7d70: 0x3442fbfb  ori         $v0, $v0, 0xFBFB
    ctx->pc = 0x1e7d70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64507);
    // 0x1e7d74: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e7d74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e7d78: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e7d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7d7c: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1e7d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1e7d80: 0x24428ca8  addiu       $v0, $v0, -0x7358
    ctx->pc = 0x1e7d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937768));
    // 0x1e7d84: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1e7d84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7d88: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7d88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7d8c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7d90: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7d90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7d94: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7d94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7d98: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e7d98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7d9c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7da0: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1e7da0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7da4: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x1e7da4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x1e7da8: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x1e7da8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
    // 0x1e7dac: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e7dacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7db0: 0x3c02fafa  lui         $v0, 0xFAFA
    ctx->pc = 0x1e7db0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64250 << 16));
    // 0x1e7db4: 0x3442fafa  ori         $v0, $v0, 0xFAFA
    ctx->pc = 0x1e7db4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64250);
    // 0x1e7db8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e7db8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e7dbc: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E7DBCu;
    {
        const bool branch_taken_0x1e7dbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7dbc) {
            ctx->pc = 0x1E7E04u;
            goto label_1e7e04;
        }
    }
    ctx->pc = 0x1E7DC4u;
label_1e7dc4:
    // 0x1e7dc4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7dc8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e7dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7dcc: 0x3c02fbfb  lui         $v0, 0xFBFB
    ctx->pc = 0x1e7dccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64507 << 16));
    // 0x1e7dd0: 0x3442fbfb  ori         $v0, $v0, 0xFBFB
    ctx->pc = 0x1e7dd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64507);
    // 0x1e7dd4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7DD4u;
    {
        const bool branch_taken_0x1e7dd4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e7dd4) {
            ctx->pc = 0x1E7DE4u;
            goto label_1e7de4;
        }
    }
    ctx->pc = 0x1E7DDCu;
    // 0x1e7ddc: 0xc040dd4  jal         func_103750
    ctx->pc = 0x1E7DDCu;
    SET_GPR_U32(ctx, 31, 0x1E7DE4u);
    ctx->pc = 0x103750u;
    if (runtime->hasFunction(0x103750u)) {
        auto targetFn = runtime->lookupFunction(0x103750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7DE4u; }
        if (ctx->pc != 0x1E7DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103750_0x103750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7DE4u; }
        if (ctx->pc != 0x1E7DE4u) { return; }
    }
    ctx->pc = 0x1E7DE4u;
label_1e7de4:
    // 0x1e7de4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7de8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e7de8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7dec: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e7decu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e7df0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7df4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e7df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7df8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e7df8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e7dfc: 0x1000ffb3  b           . + 4 + (-0x4D << 2)
    ctx->pc = 0x1E7DFCu;
    {
        const bool branch_taken_0x1e7dfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7dfc) {
            ctx->pc = 0x1E7CCCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7ccc;
        }
    }
    ctx->pc = 0x1E7E04u;
label_1e7e04:
    // 0x1e7e04: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7e04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7e08: 0x3403cb20  ori         $v1, $zero, 0xCB20
    ctx->pc = 0x1e7e08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)52000);
    // 0x1e7e0c: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1e7e0cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1e7e10: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E7E10u;
    {
        const bool branch_taken_0x1e7e10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7e10) {
            ctx->pc = 0x1E7E24u;
            goto label_1e7e24;
        }
    }
    ctx->pc = 0x1E7E18u;
    // 0x1e7e18: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e7e18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7e1c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E7E1Cu;
    {
        const bool branch_taken_0x1e7e1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7e1c) {
            ctx->pc = 0x1E7E28u;
            goto label_1e7e28;
        }
    }
    ctx->pc = 0x1E7E24u;
label_1e7e24:
    // 0x1e7e24: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e7e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1e7e28:
    // 0x1e7e28: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7e28u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7e2c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e7e2cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e7e30: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e7e30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e7e34: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e7e34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e7e38: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7E38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7CB4u: goto label_1e7cb4;
            case 0x1E7CCCu: goto label_1e7ccc;
            case 0x1E7CE8u: goto label_1e7ce8;
            case 0x1E7DC4u: goto label_1e7dc4;
            case 0x1E7DE4u: goto label_1e7de4;
            case 0x1E7E04u: goto label_1e7e04;
            case 0x1E7E24u: goto label_1e7e24;
            case 0x1E7E28u: goto label_1e7e28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7E40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

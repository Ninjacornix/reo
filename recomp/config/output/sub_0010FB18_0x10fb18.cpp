#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010FB18
// Address: 0x10fb18 - 0x1101b0
void sub_0010FB18_0x10fb18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010FB18_0x10fb18");
#endif

    ctx->pc = 0x10fb18u;

    // 0x10fb18: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x10fb18u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fb1c: 0x9503f  dsra32      $t2, $t1, 0
    ctx->pc = 0x10fb1cu;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 9) >> (32 + 0));
    // 0x10fb20: 0xa203c  dsll32      $a0, $t2, 0
    ctx->pc = 0x10fb20u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) << (32 + 0));
    // 0x10fb24: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x10fb24u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x10fb28: 0x4810016  bgez        $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x10FB28u;
    {
        const bool branch_taken_0x10fb28 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x10FB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FB28u;
            // 0x10fb2c: 0xc02d  daddu       $t8, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fb28) {
            ctx->pc = 0x10FB84u;
            goto label_10fb84;
        }
    }
    ctx->pc = 0x10FB30u;
    // 0x10fb30: 0x9103c  dsll32      $v0, $t1, 0
    ctx->pc = 0x10fb30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) << (32 + 0));
    // 0x10fb34: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10fb34u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10fb38: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10fb38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10fb3c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10fb3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10fb40: 0x21023  negu        $v0, $v0
    ctx->pc = 0x10fb40u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x10fb44: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x10fb44u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x10fb48: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10fb48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10fb4c: 0x41823  negu        $v1, $a0
    ctx->pc = 0x10fb4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x10fb50: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x10fb50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x10fb54: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x10fb54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x10fb58: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x10fb58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x10fb5c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x10fb5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x10fb60: 0x2418ffff  addiu       $t8, $zero, -0x1
    ctx->pc = 0x10fb60u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10fb64: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x10fb64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x10fb68: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10fb68u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10fb6c: 0xc43024  and         $a2, $a2, $a0
    ctx->pc = 0x10fb6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 4));
    // 0x10fb70: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x10fb70u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x10fb74: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x10fb74u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10fb78: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10fb78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10fb7c: 0xc34825  or          $t1, $a2, $v1
    ctx->pc = 0x10fb7cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x10fb80: 0x9503f  dsra32      $t2, $t1, 0
    ctx->pc = 0x10fb80u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 9) >> (32 + 0));
label_10fb84:
    // 0x10fb84: 0x5203f  dsra32      $a0, $a1, 0
    ctx->pc = 0x10fb84u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x10fb88: 0x4810015  bgez        $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x10FB88u;
    {
        const bool branch_taken_0x10fb88 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x10fb88) {
            ctx->pc = 0x10FBE0u;
            goto label_10fbe0;
        }
    }
    ctx->pc = 0x10FB90u;
    // 0x10fb90: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x10fb90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10fb94: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10fb94u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10fb98: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10fb98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10fb9c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10fb9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10fba0: 0x21023  negu        $v0, $v0
    ctx->pc = 0x10fba0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x10fba4: 0xe33824  and         $a3, $a3, $v1
    ctx->pc = 0x10fba4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 3));
    // 0x10fba8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10fba8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10fbac: 0x41823  negu        $v1, $a0
    ctx->pc = 0x10fbacu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x10fbb0: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x10fbb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x10fbb4: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x10fbb4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x10fbb8: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x10fbb8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x10fbbc: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x10fbbcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x10fbc0: 0x18c027  nor         $t8, $zero, $t8
    ctx->pc = 0x10fbc0u;
    SET_GPR_U64(ctx, 24, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 24)));
    // 0x10fbc4: 0x7103c  dsll32      $v0, $a3, 0
    ctx->pc = 0x10fbc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 0));
    // 0x10fbc8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10fbc8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10fbcc: 0xe43824  and         $a3, $a3, $a0
    ctx->pc = 0x10fbccu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 4));
    // 0x10fbd0: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x10fbd0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x10fbd4: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x10fbd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10fbd8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10fbd8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10fbdc: 0xe32825  or          $a1, $a3, $v1
    ctx->pc = 0x10fbdcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
label_10fbe0:
    // 0x10fbe0: 0x5403f  dsra32      $t0, $a1, 0
    ctx->pc = 0x10fbe0u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x10fbe4: 0x9583c  dsll32      $t3, $t1, 0
    ctx->pc = 0x10fbe4u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 9) << (32 + 0));
    // 0x10fbe8: 0xb583f  dsra32      $t3, $t3, 0
    ctx->pc = 0x10fbe8u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 11) >> (32 + 0));
    // 0x10fbec: 0xa503c  dsll32      $t2, $t2, 0
    ctx->pc = 0x10fbecu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) << (32 + 0));
    // 0x10fbf0: 0xa503f  dsra32      $t2, $t2, 0
    ctx->pc = 0x10fbf0u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 10) >> (32 + 0));
    // 0x10fbf4: 0x5483c  dsll32      $t1, $a1, 0
    ctx->pc = 0x10fbf4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10fbf8: 0x9483f  dsra32      $t1, $t1, 0
    ctx->pc = 0x10fbf8u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 0));
    // 0x10fbfc: 0x150000e2  bnez        $t0, . + 4 + (0xE2 << 2)
    ctx->pc = 0x10FBFCu;
    {
        const bool branch_taken_0x10fbfc = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FBFCu;
            // 0x10fc00: 0x148102b  sltu        $v0, $t2, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fbfc) {
            ctx->pc = 0x10FF88u;
            goto label_10ff88;
        }
    }
    ctx->pc = 0x10FC04u;
    // 0x10fc04: 0x149102b  sltu        $v0, $t2, $t1
    ctx->pc = 0x10fc04u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fc08: 0x1040004f  beqz        $v0, . + 4 + (0x4F << 2)
    ctx->pc = 0x10FC08u;
    {
        const bool branch_taken_0x10fc08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FC08u;
            // 0x10fc0c: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fc08) {
            ctx->pc = 0x10FD48u;
            goto label_10fd48;
        }
    }
    ctx->pc = 0x10FC10u;
    // 0x10fc10: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x10fc10u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fc14: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10FC14u;
    {
        const bool branch_taken_0x10fc14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FC18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FC14u;
            // 0x10fc18: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fc14) {
            ctx->pc = 0x10FC30u;
            goto label_10fc30;
        }
    }
    ctx->pc = 0x10FC1Cu;
    // 0x10fc1c: 0x2d220100  sltiu       $v0, $t1, 0x100
    ctx->pc = 0x10fc1cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x10fc20: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x10fc20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10fc24: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x10FC24u;
    {
        const bool branch_taken_0x10fc24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FC28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FC24u;
            // 0x10fc28: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fc24) {
            ctx->pc = 0x10FC44u;
            goto label_10fc44;
        }
    }
    ctx->pc = 0x10FC2Cu;
    // 0x10fc2c: 0x0  nop
    ctx->pc = 0x10fc2cu;
    // NOP
label_10fc30:
    // 0x10fc30: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x10fc30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x10fc34: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10fc34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10fc38: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x10fc38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10fc3c: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x10fc3cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fc40: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x10fc40u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_10fc44:
    // 0x10fc44: 0x891806  srlv        $v1, $t1, $a0
    ctx->pc = 0x10fc44u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 4) & 0x1F));
    // 0x10fc48: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x10fc48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x10fc4c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x10fc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x10fc50: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10fc50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10fc54: 0x904281a0  lbu         $v0, -0x7E60($v0)
    ctx->pc = 0x10fc54u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294934944)));
    // 0x10fc58: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10fc58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10fc5c: 0xa23023  subu        $a2, $a1, $v0
    ctx->pc = 0x10fc5cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x10fc60: 0x10c00006  beqz        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x10FC60u;
    {
        const bool branch_taken_0x10fc60 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FC60u;
            // 0x10fc64: 0xa61023  subu        $v0, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fc60) {
            ctx->pc = 0x10FC7Cu;
            goto label_10fc7c;
        }
    }
    ctx->pc = 0x10FC68u;
    // 0x10fc68: 0xca1804  sllv        $v1, $t2, $a2
    ctx->pc = 0x10fc68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 6) & 0x1F));
    // 0x10fc6c: 0x4b1006  srlv        $v0, $t3, $v0
    ctx->pc = 0x10fc6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), GPR_U32(ctx, 2) & 0x1F));
    // 0x10fc70: 0xcb5804  sllv        $t3, $t3, $a2
    ctx->pc = 0x10fc70u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 6) & 0x1F));
    // 0x10fc74: 0x625025  or          $t2, $v1, $v0
    ctx->pc = 0x10fc74u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x10fc78: 0xc94804  sllv        $t1, $t1, $a2
    ctx->pc = 0x10fc78u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
label_10fc7c:
    // 0x10fc7c: 0x93402  srl         $a2, $t1, 16
    ctx->pc = 0x10fc7cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x10fc80: 0x3128ffff  andi        $t0, $t1, 0xFFFF
    ctx->pc = 0x10fc80u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x10fc84: 0x146001b  divu        $zero, $t2, $a2
    ctx->pc = 0x10fc84u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,10); } }
    // 0x10fc88: 0xb2402  srl         $a0, $t3, 16
    ctx->pc = 0x10fc88u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 11), 16));
    // 0x10fc8c: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FC8Cu;
    {
        const bool branch_taken_0x10fc8c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fc8c) {
            ctx->pc = 0x10FC90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FC8Cu;
            // 0x10fc90: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FC94u;
            goto label_10fc94;
        }
    }
    ctx->pc = 0x10FC94u;
label_10fc94:
    // 0x10fc94: 0x1012  mflo        $v0
    ctx->pc = 0x10fc94u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10fc98: 0x1810  mfhi        $v1
    ctx->pc = 0x10fc98u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x10fc9c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x10fc9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fca0: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x10fca0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x10fca4: 0xe82818  mult        $a1, $a3, $t0
    ctx->pc = 0x10fca4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x10fca8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x10fca8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x10fcac: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fcacu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fcb0: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10FCB0u;
    {
        const bool branch_taken_0x10fcb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fcb0) {
            ctx->pc = 0x10FCB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FCB0u;
            // 0x10fcb4: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FCE4u;
            goto label_10fce4;
        }
    }
    ctx->pc = 0x10FCB8u;
    // 0x10fcb8: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fcb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10fcbc: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x10fcbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fcc0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10FCC0u;
    {
        const bool branch_taken_0x10fcc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FCC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FCC0u;
            // 0x10fcc4: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fcc0) {
            ctx->pc = 0x10FCE0u;
            goto label_10fce0;
        }
    }
    ctx->pc = 0x10FCC8u;
    // 0x10fcc8: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fcc8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fccc: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10FCCCu;
    {
        const bool branch_taken_0x10fccc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fccc) {
            ctx->pc = 0x10FCD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FCCCu;
            // 0x10fcd0: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FCE4u;
            goto label_10fce4;
        }
    }
    ctx->pc = 0x10FCD4u;
    // 0x10fcd4: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10fcd4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10fcd8: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fcd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10fcdc: 0x0  nop
    ctx->pc = 0x10fcdcu;
    // NOP
label_10fce0:
    // 0x10fce0: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x10fce0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_10fce4:
    // 0x10fce4: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FCE4u;
    {
        const bool branch_taken_0x10fce4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fce4) {
            ctx->pc = 0x10FCE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FCE4u;
            // 0x10fce8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FCECu;
            goto label_10fcec;
        }
    }
    ctx->pc = 0x10FCECu;
label_10fcec:
    // 0x10fcec: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x10fcecu;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x10fcf0: 0x3164ffff  andi        $a0, $t3, 0xFFFF
    ctx->pc = 0x10fcf0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65535);
    // 0x10fcf4: 0x1012  mflo        $v0
    ctx->pc = 0x10fcf4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10fcf8: 0x1810  mfhi        $v1
    ctx->pc = 0x10fcf8u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x10fcfc: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x10fcfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fd00: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x10fd00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x10fd04: 0xc82818  mult        $a1, $a2, $t0
    ctx->pc = 0x10fd04u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x10fd08: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x10fd08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x10fd0c: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fd0cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fd10: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10FD10u;
    {
        const bool branch_taken_0x10fd10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FD14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD10u;
            // 0x10fd14: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fd10) {
            ctx->pc = 0x10FD3Cu;
            goto label_10fd3c;
        }
    }
    ctx->pc = 0x10FD18u;
    // 0x10fd18: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fd18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10fd1c: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x10fd1cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fd20: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10FD20u;
    {
        const bool branch_taken_0x10fd20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FD24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD20u;
            // 0x10fd24: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fd20) {
            ctx->pc = 0x10FD38u;
            goto label_10fd38;
        }
    }
    ctx->pc = 0x10FD28u;
    // 0x10fd28: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fd28u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fd2c: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x10fd2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x10fd30: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x10fd30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x10fd34: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x10fd34u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_10fd38:
    // 0x10fd38: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x10fd38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_10fd3c:
    // 0x10fd3c: 0x100000fc  b           . + 4 + (0xFC << 2)
    ctx->pc = 0x10FD3Cu;
    {
        const bool branch_taken_0x10fd3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FD40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD3Cu;
            // 0x10fd40: 0x463025  or          $a2, $v0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fd3c) {
            ctx->pc = 0x110130u;
            goto label_110130;
        }
    }
    ctx->pc = 0x10FD44u;
    // 0x10fd44: 0x0  nop
    ctx->pc = 0x10fd44u;
    // NOP
label_10fd48:
    // 0x10fd48: 0x15200009  bnez        $t1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10FD48u;
    {
        const bool branch_taken_0x10fd48 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD48u;
            // 0x10fd4c: 0x49102b  sltu        $v0, $v0, $t1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fd48) {
            ctx->pc = 0x10FD70u;
            goto label_10fd70;
        }
    }
    ctx->pc = 0x10FD50u;
    // 0x10fd50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10fd50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10fd54: 0x51200001  beql        $t1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FD54u;
    {
        const bool branch_taken_0x10fd54 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fd54) {
            ctx->pc = 0x10FD58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD54u;
            // 0x10fd58: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FD5Cu;
            goto label_10fd5c;
        }
    }
    ctx->pc = 0x10FD5Cu;
label_10fd5c:
    // 0x10fd5c: 0x48001b  divu        $zero, $v0, $t0
    ctx->pc = 0x10fd5cu;
    { uint32_t divisor = GPR_U32(ctx, 8); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x10fd60: 0x1012  mflo        $v0
    ctx->pc = 0x10fd60u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10fd64: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x10fd64u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fd68: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x10fd68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x10fd6c: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x10fd6cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
label_10fd70:
    // 0x10fd70: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10FD70u;
    {
        const bool branch_taken_0x10fd70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FD74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD70u;
            // 0x10fd74: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fd70) {
            ctx->pc = 0x10FD88u;
            goto label_10fd88;
        }
    }
    ctx->pc = 0x10FD78u;
    // 0x10fd78: 0x2d220100  sltiu       $v0, $t1, 0x100
    ctx->pc = 0x10fd78u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x10fd7c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x10fd7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10fd80: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10FD80u;
    {
        const bool branch_taken_0x10fd80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FD84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FD80u;
            // 0x10fd84: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fd80) {
            ctx->pc = 0x10FD9Cu;
            goto label_10fd9c;
        }
    }
    ctx->pc = 0x10FD88u;
label_10fd88:
    // 0x10fd88: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x10fd88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x10fd8c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10fd8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10fd90: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x10fd90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10fd94: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x10fd94u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fd98: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x10fd98u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_10fd9c:
    // 0x10fd9c: 0x891806  srlv        $v1, $t1, $a0
    ctx->pc = 0x10fd9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 4) & 0x1F));
    // 0x10fda0: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x10fda0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x10fda4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x10fda4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x10fda8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10fda8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10fdac: 0x904281a0  lbu         $v0, -0x7E60($v0)
    ctx->pc = 0x10fdacu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294934944)));
    // 0x10fdb0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10fdb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10fdb4: 0xa23023  subu        $a2, $a1, $v0
    ctx->pc = 0x10fdb4u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x10fdb8: 0x14c00007  bnez        $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x10FDB8u;
    {
        const bool branch_taken_0x10fdb8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FDBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FDB8u;
            // 0x10fdbc: 0xa63823  subu        $a3, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fdb8) {
            ctx->pc = 0x10FDD8u;
            goto label_10fdd8;
        }
    }
    ctx->pc = 0x10FDC0u;
    // 0x10fdc0: 0x1495023  subu        $t2, $t2, $t1
    ctx->pc = 0x10fdc0u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x10fdc4: 0x240d0001  addiu       $t5, $zero, 0x1
    ctx->pc = 0x10fdc4u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10fdc8: 0x94402  srl         $t0, $t1, 16
    ctx->pc = 0x10fdc8u;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x10fdcc: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x10FDCCu;
    {
        const bool branch_taken_0x10fdcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FDCCu;
            // 0x10fdd0: 0x312cffff  andi        $t4, $t1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 12, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fdcc) {
            ctx->pc = 0x10FEC0u;
            goto label_10fec0;
        }
    }
    ctx->pc = 0x10FDD4u;
    // 0x10fdd4: 0x0  nop
    ctx->pc = 0x10fdd4u;
    // NOP
label_10fdd8:
    // 0x10fdd8: 0xca1804  sllv        $v1, $t2, $a2
    ctx->pc = 0x10fdd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 6) & 0x1F));
    // 0x10fddc: 0xeb1006  srlv        $v0, $t3, $a3
    ctx->pc = 0x10fddcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), GPR_U32(ctx, 7) & 0x1F));
    // 0x10fde0: 0xcb5804  sllv        $t3, $t3, $a2
    ctx->pc = 0x10fde0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 6) & 0x1F));
    // 0x10fde4: 0xea2006  srlv        $a0, $t2, $a3
    ctx->pc = 0x10fde4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 7) & 0x1F));
    // 0x10fde8: 0x625025  or          $t2, $v1, $v0
    ctx->pc = 0x10fde8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x10fdec: 0xc94804  sllv        $t1, $t1, $a2
    ctx->pc = 0x10fdecu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
    // 0x10fdf0: 0x94402  srl         $t0, $t1, 16
    ctx->pc = 0x10fdf0u;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x10fdf4: 0x88001b  divu        $zero, $a0, $t0
    ctx->pc = 0x10fdf4u;
    { uint32_t divisor = GPR_U32(ctx, 8); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x10fdf8: 0xa2402  srl         $a0, $t2, 16
    ctx->pc = 0x10fdf8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x10fdfc: 0x312cffff  andi        $t4, $t1, 0xFFFF
    ctx->pc = 0x10fdfcu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x10fe00: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x10fe00u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fe04: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FE04u;
    {
        const bool branch_taken_0x10fe04 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fe04) {
            ctx->pc = 0x10FE08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE04u;
            // 0x10fe08: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FE0Cu;
            goto label_10fe0c;
        }
    }
    ctx->pc = 0x10FE0Cu;
label_10fe0c:
    // 0x10fe0c: 0x1012  mflo        $v0
    ctx->pc = 0x10fe0cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10fe10: 0x1810  mfhi        $v1
    ctx->pc = 0x10fe10u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x10fe14: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x10fe14u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fe18: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x10fe18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x10fe1c: 0xec2818  mult        $a1, $a3, $t4
    ctx->pc = 0x10fe1cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x10fe20: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x10fe20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x10fe24: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fe24u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fe28: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x10FE28u;
    {
        const bool branch_taken_0x10fe28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FE2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE28u;
            // 0x10fe2c: 0x180682d  daddu       $t5, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fe28) {
            ctx->pc = 0x10FE58u;
            goto label_10fe58;
        }
    }
    ctx->pc = 0x10FE30u;
    // 0x10fe30: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fe30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10fe34: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x10fe34u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fe38: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10FE38u;
    {
        const bool branch_taken_0x10fe38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE38u;
            // 0x10fe3c: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fe38) {
            ctx->pc = 0x10FE58u;
            goto label_10fe58;
        }
    }
    ctx->pc = 0x10FE40u;
    // 0x10fe40: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fe40u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fe44: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10FE44u;
    {
        const bool branch_taken_0x10fe44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fe44) {
            ctx->pc = 0x10FE48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE44u;
            // 0x10fe48: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FE5Cu;
            goto label_10fe5c;
        }
    }
    ctx->pc = 0x10FE4Cu;
    // 0x10fe4c: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10fe4cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10fe50: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fe50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10fe54: 0x0  nop
    ctx->pc = 0x10fe54u;
    // NOP
label_10fe58:
    // 0x10fe58: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x10fe58u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_10fe5c:
    // 0x10fe5c: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FE5Cu;
    {
        const bool branch_taken_0x10fe5c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fe5c) {
            ctx->pc = 0x10FE60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE5Cu;
            // 0x10fe60: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FE64u;
            goto label_10fe64;
        }
    }
    ctx->pc = 0x10FE64u;
label_10fe64:
    // 0x10fe64: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x10fe64u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x10fe68: 0x3144ffff  andi        $a0, $t2, 0xFFFF
    ctx->pc = 0x10fe68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x10fe6c: 0x1012  mflo        $v0
    ctx->pc = 0x10fe6cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10fe70: 0x1810  mfhi        $v1
    ctx->pc = 0x10fe70u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x10fe74: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x10fe74u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fe78: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x10fe78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x10fe7c: 0xcd2818  mult        $a1, $a2, $t5
    ctx->pc = 0x10fe7cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x10fe80: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x10fe80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x10fe84: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fe84u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fe88: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x10FE88u;
    {
        const bool branch_taken_0x10fe88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE88u;
            // 0x10fe8c: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fe88) {
            ctx->pc = 0x10FEB8u;
            goto label_10feb8;
        }
    }
    ctx->pc = 0x10FE90u;
    // 0x10fe90: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fe90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10fe94: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x10fe94u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10fe98: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10FE98u;
    {
        const bool branch_taken_0x10fe98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FE9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FE98u;
            // 0x10fe9c: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fe98) {
            ctx->pc = 0x10FEB4u;
            goto label_10feb4;
        }
    }
    ctx->pc = 0x10FEA0u;
    // 0x10fea0: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fea0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fea4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10FEA4u;
    {
        const bool branch_taken_0x10fea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FEA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FEA4u;
            // 0x10fea8: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fea4) {
            ctx->pc = 0x10FEB8u;
            goto label_10feb8;
        }
    }
    ctx->pc = 0x10FEACu;
    // 0x10feac: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x10feacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x10feb0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10feb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
label_10feb4:
    // 0x10feb4: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x10feb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_10feb8:
    // 0x10feb8: 0x655023  subu        $t2, $v1, $a1
    ctx->pc = 0x10feb8u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10febc: 0x466825  or          $t5, $v0, $a2
    ctx->pc = 0x10febcu;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
label_10fec0:
    // 0x10fec0: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x10fec0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fec4: 0x180402d  daddu       $t0, $t4, $zero
    ctx->pc = 0x10fec4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fec8: 0x146001b  divu        $zero, $t2, $a2
    ctx->pc = 0x10fec8u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,10); } }
    // 0x10fecc: 0xb2402  srl         $a0, $t3, 16
    ctx->pc = 0x10feccu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 11), 16));
    // 0x10fed0: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FED0u;
    {
        const bool branch_taken_0x10fed0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fed0) {
            ctx->pc = 0x10FED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FED0u;
            // 0x10fed4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FED8u;
            goto label_10fed8;
        }
    }
    ctx->pc = 0x10FED8u;
label_10fed8:
    // 0x10fed8: 0x1012  mflo        $v0
    ctx->pc = 0x10fed8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10fedc: 0x1810  mfhi        $v1
    ctx->pc = 0x10fedcu;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x10fee0: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x10fee0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fee4: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x10fee4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x10fee8: 0xe82818  mult        $a1, $a3, $t0
    ctx->pc = 0x10fee8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x10feec: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x10feecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x10fef0: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10fef0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10fef4: 0x5040000b  beql        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x10FEF4u;
    {
        const bool branch_taken_0x10fef4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10fef4) {
            ctx->pc = 0x10FEF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FEF4u;
            // 0x10fef8: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FF24u;
            goto label_10ff24;
        }
    }
    ctx->pc = 0x10FEFCu;
    // 0x10fefc: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10fefcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10ff00: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x10ff00u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10ff04: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10FF04u;
    {
        const bool branch_taken_0x10ff04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FF08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF04u;
            // 0x10ff08: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff04) {
            ctx->pc = 0x10FF20u;
            goto label_10ff20;
        }
    }
    ctx->pc = 0x10FF0Cu;
    // 0x10ff0c: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10ff0cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10ff10: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10FF10u;
    {
        const bool branch_taken_0x10ff10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ff10) {
            ctx->pc = 0x10FF14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF10u;
            // 0x10ff14: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FF24u;
            goto label_10ff24;
        }
    }
    ctx->pc = 0x10FF18u;
    // 0x10ff18: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10ff18u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10ff1c: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10ff1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
label_10ff20:
    // 0x10ff20: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x10ff20u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_10ff24:
    // 0x10ff24: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10FF24u;
    {
        const bool branch_taken_0x10ff24 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ff24) {
            ctx->pc = 0x10FF28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF24u;
            // 0x10ff28: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FF2Cu;
            goto label_10ff2c;
        }
    }
    ctx->pc = 0x10FF2Cu;
label_10ff2c:
    // 0x10ff2c: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x10ff2cu;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x10ff30: 0x3164ffff  andi        $a0, $t3, 0xFFFF
    ctx->pc = 0x10ff30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65535);
    // 0x10ff34: 0x1012  mflo        $v0
    ctx->pc = 0x10ff34u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x10ff38: 0x1810  mfhi        $v1
    ctx->pc = 0x10ff38u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x10ff3c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x10ff3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ff40: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x10ff40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x10ff44: 0xc82818  mult        $a1, $a2, $t0
    ctx->pc = 0x10ff44u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x10ff48: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x10ff48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x10ff4c: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10ff4cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10ff50: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10FF50u;
    {
        const bool branch_taken_0x10ff50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FF54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF50u;
            // 0x10ff54: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff50) {
            ctx->pc = 0x10FF7Cu;
            goto label_10ff7c;
        }
    }
    ctx->pc = 0x10FF58u;
    // 0x10ff58: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x10ff58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x10ff5c: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x10ff5cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10ff60: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10FF60u;
    {
        const bool branch_taken_0x10ff60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FF64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF60u;
            // 0x10ff64: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff60) {
            ctx->pc = 0x10FF78u;
            goto label_10ff78;
        }
    }
    ctx->pc = 0x10FF68u;
    // 0x10ff68: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x10ff68u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10ff6c: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x10ff6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x10ff70: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x10ff70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x10ff74: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x10ff74u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_10ff78:
    // 0x10ff78: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x10ff78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_10ff7c:
    // 0x10ff7c: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x10FF7Cu;
    {
        const bool branch_taken_0x10ff7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FF80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF7Cu;
            // 0x10ff80: 0x463025  or          $a2, $v0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff7c) {
            ctx->pc = 0x110134u;
            goto label_110134;
        }
    }
    ctx->pc = 0x10FF84u;
    // 0x10ff84: 0x0  nop
    ctx->pc = 0x10ff84u;
    // NOP
label_10ff88:
    // 0x10ff88: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10FF88u;
    {
        const bool branch_taken_0x10ff88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FF8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF88u;
            // 0x10ff8c: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff88) {
            ctx->pc = 0x10FF98u;
            goto label_10ff98;
        }
    }
    ctx->pc = 0x10FF90u;
    // 0x10ff90: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x10FF90u;
    {
        const bool branch_taken_0x10ff90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FF94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF90u;
            // 0x10ff94: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff90) {
            ctx->pc = 0x110130u;
            goto label_110130;
        }
    }
    ctx->pc = 0x10FF98u;
label_10ff98:
    // 0x10ff98: 0x48102b  sltu        $v0, $v0, $t0
    ctx->pc = 0x10ff98u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x10ff9c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10FF9Cu;
    {
        const bool branch_taken_0x10ff9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FFA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FF9Cu;
            // 0x10ffa0: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ff9c) {
            ctx->pc = 0x10FFB8u;
            goto label_10ffb8;
        }
    }
    ctx->pc = 0x10FFA4u;
    // 0x10ffa4: 0x2d020100  sltiu       $v0, $t0, 0x100
    ctx->pc = 0x10ffa4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x10ffa8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x10ffa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10ffac: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x10FFACu;
    {
        const bool branch_taken_0x10ffac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FFACu;
            // 0x10ffb0: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ffac) {
            ctx->pc = 0x10FFCCu;
            goto label_10ffcc;
        }
    }
    ctx->pc = 0x10FFB4u;
    // 0x10ffb4: 0x0  nop
    ctx->pc = 0x10ffb4u;
    // NOP
label_10ffb8:
    // 0x10ffb8: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x10ffb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x10ffbc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10ffbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10ffc0: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x10ffc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10ffc4: 0x48102b  sltu        $v0, $v0, $t0
    ctx->pc = 0x10ffc4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x10ffc8: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x10ffc8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_10ffcc:
    // 0x10ffcc: 0x881806  srlv        $v1, $t0, $a0
    ctx->pc = 0x10ffccu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 4) & 0x1F));
    // 0x10ffd0: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x10ffd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x10ffd4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x10ffd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x10ffd8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10ffd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10ffdc: 0x904281a0  lbu         $v0, -0x7E60($v0)
    ctx->pc = 0x10ffdcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294934944)));
    // 0x10ffe0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10ffe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10ffe4: 0xa23023  subu        $a2, $a1, $v0
    ctx->pc = 0x10ffe4u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x10ffe8: 0x14c00009  bnez        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x10FFE8u;
    {
        const bool branch_taken_0x10ffe8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FFECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FFE8u;
            // 0x10ffec: 0xa63823  subu        $a3, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ffe8) {
            ctx->pc = 0x110010u;
            goto label_110010;
        }
    }
    ctx->pc = 0x10FFF0u;
    // 0x10fff0: 0x10a102b  sltu        $v0, $t0, $t2
    ctx->pc = 0x10fff0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 10)) ? 1 : 0);
    // 0x10fff4: 0x1440004e  bnez        $v0, . + 4 + (0x4E << 2)
    ctx->pc = 0x10FFF4u;
    {
        const bool branch_taken_0x10fff4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FFF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FFF4u;
            // 0x10fff8: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fff4) {
            ctx->pc = 0x110130u;
            goto label_110130;
        }
    }
    ctx->pc = 0x10FFFCu;
    // 0x10fffc: 0x169102b  sltu        $v0, $t3, $t1
    ctx->pc = 0x10fffcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110000: 0x1440004b  bnez        $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x110000u;
    {
        const bool branch_taken_0x110000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110000u;
            // 0x110004: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110000) {
            ctx->pc = 0x110130u;
            goto label_110130;
        }
    }
    ctx->pc = 0x110008u;
    // 0x110008: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x110008u;
    {
        const bool branch_taken_0x110008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11000Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110008u;
            // 0x11000c: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110008) {
            ctx->pc = 0x110130u;
            goto label_110130;
        }
    }
    ctx->pc = 0x110010u;
label_110010:
    // 0x110010: 0xc82004  sllv        $a0, $t0, $a2
    ctx->pc = 0x110010u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 6) & 0x1F));
    // 0x110014: 0xeb2806  srlv        $a1, $t3, $a3
    ctx->pc = 0x110014u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 11), GPR_U32(ctx, 7) & 0x1F));
    // 0x110018: 0xcb5804  sllv        $t3, $t3, $a2
    ctx->pc = 0x110018u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 6) & 0x1F));
    // 0x11001c: 0xe91006  srlv        $v0, $t1, $a3
    ctx->pc = 0x11001cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 7) & 0x1F));
    // 0x110020: 0xc94804  sllv        $t1, $t1, $a2
    ctx->pc = 0x110020u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
    // 0x110024: 0xca1804  sllv        $v1, $t2, $a2
    ctx->pc = 0x110024u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 6) & 0x1F));
    // 0x110028: 0x824025  or          $t0, $a0, $v0
    ctx->pc = 0x110028u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x11002c: 0xea2006  srlv        $a0, $t2, $a3
    ctx->pc = 0x11002cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 7) & 0x1F));
    // 0x110030: 0x655025  or          $t2, $v1, $a1
    ctx->pc = 0x110030u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x110034: 0x82c02  srl         $a1, $t0, 16
    ctx->pc = 0x110034u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 8), 16));
    // 0x110038: 0x85001b  divu        $zero, $a0, $a1
    ctx->pc = 0x110038u;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x11003c: 0xa2402  srl         $a0, $t2, 16
    ctx->pc = 0x11003cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x110040: 0x310cffff  andi        $t4, $t0, 0xFFFF
    ctx->pc = 0x110040u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
    // 0x110044: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110044u;
    {
        const bool branch_taken_0x110044 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x110044) {
            ctx->pc = 0x110048u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110044u;
            // 0x110048: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x11004Cu;
            goto label_11004c;
        }
    }
    ctx->pc = 0x11004Cu;
label_11004c:
    // 0x11004c: 0x1012  mflo        $v0
    ctx->pc = 0x11004cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110050: 0x1810  mfhi        $v1
    ctx->pc = 0x110050u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110054: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x110054u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110058: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110058u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x11005c: 0xec3018  mult        $a2, $a3, $t4
    ctx->pc = 0x11005cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x110060: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110060u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110064: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x110064u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110068: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x110068u;
    {
        const bool branch_taken_0x110068 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110068) {
            ctx->pc = 0x11006Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110068u;
            // 0x11006c: 0x661823  subu        $v1, $v1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11009Cu;
            goto label_11009c;
        }
    }
    ctx->pc = 0x110070u;
    // 0x110070: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x110070u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x110074: 0x68102b  sltu        $v0, $v1, $t0
    ctx->pc = 0x110074u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110078: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x110078u;
    {
        const bool branch_taken_0x110078 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11007Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110078u;
            // 0x11007c: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110078) {
            ctx->pc = 0x110098u;
            goto label_110098;
        }
    }
    ctx->pc = 0x110080u;
    // 0x110080: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x110080u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110084: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x110084u;
    {
        const bool branch_taken_0x110084 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110084) {
            ctx->pc = 0x110088u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110084u;
            // 0x110088: 0x661823  subu        $v1, $v1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11009Cu;
            goto label_11009c;
        }
    }
    ctx->pc = 0x11008Cu;
    // 0x11008c: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x11008cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x110090: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x110090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x110094: 0x0  nop
    ctx->pc = 0x110094u;
    // NOP
label_110098:
    // 0x110098: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x110098u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_11009c:
    // 0x11009c: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x11009Cu;
    {
        const bool branch_taken_0x11009c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x11009c) {
            ctx->pc = 0x1100A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11009Cu;
            // 0x1100a0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1100A4u;
            goto label_1100a4;
        }
    }
    ctx->pc = 0x1100A4u;
label_1100a4:
    // 0x1100a4: 0x65001b  divu        $zero, $v1, $a1
    ctx->pc = 0x1100a4u;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x1100a8: 0x3144ffff  andi        $a0, $t2, 0xFFFF
    ctx->pc = 0x1100a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x1100ac: 0x1012  mflo        $v0
    ctx->pc = 0x1100acu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1100b0: 0x1810  mfhi        $v1
    ctx->pc = 0x1100b0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1100b4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1100b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1100b8: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1100b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1100bc: 0xac3018  mult        $a2, $a1, $t4
    ctx->pc = 0x1100bcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x1100c0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1100c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1100c4: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x1100c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x1100c8: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1100C8u;
    {
        const bool branch_taken_0x1100c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1100CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1100C8u;
            // 0x1100cc: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1100c8) {
            ctx->pc = 0x1100F8u;
            goto label_1100f8;
        }
    }
    ctx->pc = 0x1100D0u;
    // 0x1100d0: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1100d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1100d4: 0x68102b  sltu        $v0, $v1, $t0
    ctx->pc = 0x1100d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1100d8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1100D8u;
    {
        const bool branch_taken_0x1100d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1100DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1100D8u;
            // 0x1100dc: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1100d8) {
            ctx->pc = 0x1100F4u;
            goto label_1100f4;
        }
    }
    ctx->pc = 0x1100E0u;
    // 0x1100e0: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x1100e0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x1100e4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1100E4u;
    {
        const bool branch_taken_0x1100e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1100E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1100E4u;
            // 0x1100e8: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1100e4) {
            ctx->pc = 0x1100F8u;
            goto label_1100f8;
        }
    }
    ctx->pc = 0x1100ECu;
    // 0x1100ec: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1100ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1100f0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1100f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
label_1100f4:
    // 0x1100f4: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x1100f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_1100f8:
    // 0x1100f8: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x1100f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1100fc: 0x453025  or          $a2, $v0, $a1
    ctx->pc = 0x1100fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x110100: 0xc90019  multu       $a2, $t1
    ctx->pc = 0x110100u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 6) * (uint64_t)GPR_U32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x110104: 0x3810  mfhi        $a3
    ctx->pc = 0x110104u;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x110108: 0x2012  mflo        $a0
    ctx->pc = 0x110108u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x11010c: 0x67102b  sltu        $v0, $v1, $a3
    ctx->pc = 0x11010cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x110110: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x110110u;
    {
        const bool branch_taken_0x110110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x110110) {
            ctx->pc = 0x110114u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110110u;
            // 0x110114: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110130u;
            goto label_110130;
        }
    }
    ctx->pc = 0x110118u;
    // 0x110118: 0x14e30006  bne         $a3, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x110118u;
    {
        const bool branch_taken_0x110118 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        ctx->pc = 0x11011Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110118u;
            // 0x11011c: 0x682d  daddu       $t5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110118) {
            ctx->pc = 0x110134u;
            goto label_110134;
        }
    }
    ctx->pc = 0x110120u;
    // 0x110120: 0x164102b  sltu        $v0, $t3, $a0
    ctx->pc = 0x110120u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x110124: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x110124u;
    {
        const bool branch_taken_0x110124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110124u;
            // 0x110128: 0x6103c  dsll32      $v0, $a2, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110124) {
            ctx->pc = 0x110138u;
            goto label_110138;
        }
    }
    ctx->pc = 0x11012Cu;
    // 0x11012c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x11012cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_110130:
    // 0x110130: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x110130u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_110134:
    // 0x110134: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x110134u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
label_110138:
    // 0x110138: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x110138u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11013c: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x11013cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x110140: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110140u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110144: 0x1e47824  and         $t7, $t7, $a0
    ctx->pc = 0x110144u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) & GPR_U64(ctx, 4));
    // 0x110148: 0x1e27825  or          $t7, $t7, $v0
    ctx->pc = 0x110148u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | GPR_U64(ctx, 2));
    // 0x11014c: 0xd103c  dsll32      $v0, $t5, 0
    ctx->pc = 0x11014cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 13) << (32 + 0));
    // 0x110150: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x110150u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x110154: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x110154u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x110158: 0x1e57824  and         $t7, $t7, $a1
    ctx->pc = 0x110158u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) & GPR_U64(ctx, 5));
    // 0x11015c: 0x13000011  beqz        $t8, . + 4 + (0x11 << 2)
    ctx->pc = 0x11015Cu;
    {
        const bool branch_taken_0x11015c = (GPR_U64(ctx, 24) == GPR_U64(ctx, 0));
        ctx->pc = 0x110160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11015Cu;
            // 0x110160: 0x1e21825  or          $v1, $t7, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 15) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11015c) {
            ctx->pc = 0x1101A4u;
            goto label_1101a4;
        }
    }
    ctx->pc = 0x110164u;
    // 0x110164: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x110164u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
    // 0x110168: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x110168u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11016c: 0x1c47024  and         $t6, $t6, $a0
    ctx->pc = 0x11016cu;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & GPR_U64(ctx, 4));
    // 0x110170: 0x21023  negu        $v0, $v0
    ctx->pc = 0x110170u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x110174: 0x3203f  dsra32      $a0, $v1, 0
    ctx->pc = 0x110174u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x110178: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x110178u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11017c: 0x42023  negu        $a0, $a0
    ctx->pc = 0x11017cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x110180: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110184: 0x1c27025  or          $t6, $t6, $v0
    ctx->pc = 0x110184u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | GPR_U64(ctx, 2));
    // 0x110188: 0xe183c  dsll32      $v1, $t6, 0
    ctx->pc = 0x110188u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 14) << (32 + 0));
    // 0x11018c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x11018cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x110190: 0x1c57024  and         $t6, $t6, $a1
    ctx->pc = 0x110190u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & GPR_U64(ctx, 5));
    // 0x110194: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x110194u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x110198: 0x832023  subu        $a0, $a0, $v1
    ctx->pc = 0x110198u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x11019c: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x11019cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1101a0: 0x1c41825  or          $v1, $t6, $a0
    ctx->pc = 0x1101a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 14) | GPR_U64(ctx, 4));
label_1101a4:
    // 0x1101a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1101A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1101A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1101A4u;
            // 0x1101a8: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10FB84u: goto label_10fb84;
            case 0x10FBE0u: goto label_10fbe0;
            case 0x10FC30u: goto label_10fc30;
            case 0x10FC44u: goto label_10fc44;
            case 0x10FC7Cu: goto label_10fc7c;
            case 0x10FC94u: goto label_10fc94;
            case 0x10FCE0u: goto label_10fce0;
            case 0x10FCE4u: goto label_10fce4;
            case 0x10FCECu: goto label_10fcec;
            case 0x10FD38u: goto label_10fd38;
            case 0x10FD3Cu: goto label_10fd3c;
            case 0x10FD48u: goto label_10fd48;
            case 0x10FD5Cu: goto label_10fd5c;
            case 0x10FD70u: goto label_10fd70;
            case 0x10FD88u: goto label_10fd88;
            case 0x10FD9Cu: goto label_10fd9c;
            case 0x10FDD8u: goto label_10fdd8;
            case 0x10FE0Cu: goto label_10fe0c;
            case 0x10FE58u: goto label_10fe58;
            case 0x10FE5Cu: goto label_10fe5c;
            case 0x10FE64u: goto label_10fe64;
            case 0x10FEB4u: goto label_10feb4;
            case 0x10FEB8u: goto label_10feb8;
            case 0x10FEC0u: goto label_10fec0;
            case 0x10FED8u: goto label_10fed8;
            case 0x10FF20u: goto label_10ff20;
            case 0x10FF24u: goto label_10ff24;
            case 0x10FF2Cu: goto label_10ff2c;
            case 0x10FF78u: goto label_10ff78;
            case 0x10FF7Cu: goto label_10ff7c;
            case 0x10FF88u: goto label_10ff88;
            case 0x10FF98u: goto label_10ff98;
            case 0x10FFB8u: goto label_10ffb8;
            case 0x10FFCCu: goto label_10ffcc;
            case 0x110010u: goto label_110010;
            case 0x11004Cu: goto label_11004c;
            case 0x110098u: goto label_110098;
            case 0x11009Cu: goto label_11009c;
            case 0x1100A4u: goto label_1100a4;
            case 0x1100F4u: goto label_1100f4;
            case 0x1100F8u: goto label_1100f8;
            case 0x110130u: goto label_110130;
            case 0x110134u: goto label_110134;
            case 0x110138u: goto label_110138;
            case 0x1101A4u: goto label_1101a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1101ACu;
    // 0x1101ac: 0x0  nop
    ctx->pc = 0x1101acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

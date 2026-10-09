#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BD98
// Address: 0x16bd98 - 0x16be34
void sub_0016BD98_0x16bd98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BD98_0x16bd98");
#endif

    ctx->pc = 0x16bd98u;

    // 0x16bd98: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x16bd98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16bd9c: 0x8c8a0004  lw          $t2, 0x4($a0)
    ctx->pc = 0x16bd9cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x16bda0: 0x2462000f  addiu       $v0, $v1, 0xF
    ctx->pc = 0x16bda0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x16bda4: 0x2463001e  addiu       $v1, $v1, 0x1E
    ctx->pc = 0x16bda4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 30));
    // 0x16bda8: 0x28460000  slti        $a2, $v0, 0x0
    ctx->pc = 0x16bda8u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bdac: 0x2549000f  addiu       $t1, $t2, 0xF
    ctx->pc = 0x16bdacu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 10), 15));
    // 0x16bdb0: 0x66100b  movn        $v0, $v1, $a2
    ctx->pc = 0x16bdb0u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x16bdb4: 0x292b0000  slti        $t3, $t1, 0x0
    ctx->pc = 0x16bdb4u;
    SET_GPR_U64(ctx, 11, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bdb8: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x16bdb8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x16bdbc: 0x254a001e  addiu       $t2, $t2, 0x1E
    ctx->pc = 0x16bdbcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 30));
    // 0x16bdc0: 0x24100  sll         $t0, $v0, 4
    ctx->pc = 0x16bdc0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x16bdc4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x16bdc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x16bdc8: 0x2507003f  addiu       $a3, $t0, 0x3F
    ctx->pc = 0x16bdc8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 8), 63));
    // 0x16bdcc: 0x2508007e  addiu       $t0, $t0, 0x7E
    ctx->pc = 0x16bdccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 126));
    // 0x16bdd0: 0x2446003f  addiu       $a2, $v0, 0x3F
    ctx->pc = 0x16bdd0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x16bdd4: 0x2442007e  addiu       $v0, $v0, 0x7E
    ctx->pc = 0x16bdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 126));
    // 0x16bdd8: 0x28e30000  slti        $v1, $a3, 0x0
    ctx->pc = 0x16bdd8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bddc: 0x14b480b  movn        $t1, $t2, $t3
    ctx->pc = 0x16bddcu;
    if (GPR_U64(ctx, 11) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 10));
    // 0x16bde0: 0x103380b  movn        $a3, $t0, $v1
    ctx->pc = 0x16bde0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 8));
    // 0x16bde4: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x16bde4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bde8: 0x43300b  movn        $a2, $v0, $v1
    ctx->pc = 0x16bde8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 2));
    // 0x16bdec: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x16bdecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x16bdf0: 0x73983  sra         $a3, $a3, 6
    ctx->pc = 0x16bdf0u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 6));
    // 0x16bdf4: 0x94903  sra         $t1, $t1, 4
    ctx->pc = 0x16bdf4u;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 9), 4));
    // 0x16bdf8: 0xe91018  mult        $v0, $a3, $t1
    ctx->pc = 0x16bdf8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16bdfc: 0x73980  sll         $a3, $a3, 6
    ctx->pc = 0x16bdfcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 6));
    // 0x16be00: 0x63183  sra         $a2, $a2, 6
    ctx->pc = 0x16be00u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 6));
    // 0x16be04: 0xa4a7000e  sh          $a3, 0xE($a1)
    ctx->pc = 0x16be04u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 14), (uint16_t)GPR_U32(ctx, 7));
    // 0x16be08: 0x70c94818  mult1       $t1, $a2, $t1
    ctx->pc = 0x16be08u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 9); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x16be0c: 0x63180  sll         $a2, $a2, 6
    ctx->pc = 0x16be0cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x16be10: 0xa4a6000c  sh          $a2, 0xC($a1)
    ctx->pc = 0x16be10u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 12), (uint16_t)GPR_U32(ctx, 6));
    // 0x16be14: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x16be14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x16be18: 0xaca30008  sw          $v1, 0x8($a1)
    ctx->pc = 0x16be18u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 3));
    // 0x16be1c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x16be1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16be20: 0x94a40  sll         $t1, $t1, 9
    ctx->pc = 0x16be20u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 9));
    // 0x16be24: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x16be24u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x16be28: 0x494821  addu        $t1, $v0, $t1
    ctx->pc = 0x16be28u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x16be2c: 0x3e00008  jr          $ra
    ctx->pc = 0x16BE2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BE2Cu;
            // 0x16be30: 0xaca90004  sw          $t1, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16BE34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

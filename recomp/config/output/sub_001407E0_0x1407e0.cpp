#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001407E0
// Address: 0x1407e0 - 0x1408d8
void sub_001407E0_0x1407e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001407E0_0x1407e0");
#endif

    ctx->pc = 0x1407e0u;

    // 0x1407e0: 0x68820007  ldl         $v0, 0x7($a0)
    ctx->pc = 0x1407e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1407e4: 0x6c820000  ldr         $v0, 0x0($a0)
    ctx->pc = 0x1407e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1407e8: 0xb0c20007  sdl         $v0, 0x7($a2)
    ctx->pc = 0x1407e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1407ec: 0xb4c20000  sdr         $v0, 0x0($a2)
    ctx->pc = 0x1407ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1407f0: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x1407f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1407f4: 0xace20004  sw          $v0, 0x4($a3)
    ctx->pc = 0x1407f4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 2));
    // 0x1407f8: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1407f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1407fc: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x1407fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x140800: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x140800u;
    {
        const bool branch_taken_0x140800 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140800) {
            ctx->pc = 0x140804u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140800u;
            // 0x140804: 0x8ce20004  lw          $v0, 0x4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140814u;
            goto label_140814;
        }
    }
    ctx->pc = 0x140808u;
    // 0x140808: 0xacc50004  sw          $a1, 0x4($a2)
    ctx->pc = 0x140808u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
    // 0x14080c: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x14080cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140810: 0x8ce20004  lw          $v0, 0x4($a3)
    ctx->pc = 0x140810u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_140814:
    // 0x140814: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x140814u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x140818: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x140818u;
    {
        const bool branch_taken_0x140818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14081Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140818u;
            // 0x14081c: 0xace20004  sw          $v0, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140818) {
            ctx->pc = 0x140828u;
            goto label_140828;
        }
    }
    ctx->pc = 0x140820u;
    // 0x140820: 0x3e00008  jr          $ra
    ctx->pc = 0x140820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140820u;
            // 0x140824: 0xace00000  sw          $zero, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140814u: goto label_140814;
            case 0x140828u: goto label_140828;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140828u;
label_140828:
    // 0x140828: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x140828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14082c: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x14082cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x140830: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x140830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x140834: 0x3e00008  jr          $ra
    ctx->pc = 0x140834u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140834u;
            // 0x140838: 0xace20000  sw          $v0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140814u: goto label_140814;
            case 0x140828u: goto label_140828;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14083Cu;
    // 0x14083c: 0x0  nop
    ctx->pc = 0x14083cu;
    // NOP
    // 0x140840: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x140840u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x140844: 0x3082000f  andi        $v0, $a0, 0xF
    ctx->pc = 0x140844u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x140848: 0x24639898  addiu       $v1, $v1, -0x6768
    ctx->pc = 0x140848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294940824));
    // 0x14084c: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x14084cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x140850: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x140850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x140854: 0x90460000  lbu         $a2, 0x0($v0)
    ctx->pc = 0x140854u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x140858: 0x3082000f  andi        $v0, $a0, 0xF
    ctx->pc = 0x140858u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x14085c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14085cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x140860: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x140860u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x140864: 0xa0a60006  sb          $a2, 0x6($a1)
    ctx->pc = 0x140864u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 6), (uint8_t)GPR_U32(ctx, 6));
    // 0x140868: 0x3086000f  andi        $a2, $a0, 0xF
    ctx->pc = 0x140868u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x14086c: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14086cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x140870: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x140870u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x140874: 0x90470000  lbu         $a3, 0x0($v0)
    ctx->pc = 0x140874u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x140878: 0x3082000f  andi        $v0, $a0, 0xF
    ctx->pc = 0x140878u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x14087c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14087cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x140880: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x140880u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x140884: 0xa0a70005  sb          $a3, 0x5($a1)
    ctx->pc = 0x140884u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 7));
    // 0x140888: 0x3088000f  andi        $t0, $a0, 0xF
    ctx->pc = 0x140888u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x14088c: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x14088cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x140890: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x140890u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x140894: 0x90c90000  lbu         $t1, 0x0($a2)
    ctx->pc = 0x140894u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x140898: 0x3087000f  andi        $a3, $a0, 0xF
    ctx->pc = 0x140898u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x14089c: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x14089cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1408a0: 0xe33821  addu        $a3, $a3, $v1
    ctx->pc = 0x1408a0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x1408a4: 0xa0a90004  sb          $t1, 0x4($a1)
    ctx->pc = 0x1408a4u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 4), (uint8_t)GPR_U32(ctx, 9));
    // 0x1408a8: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1408a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1408ac: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1408acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1408b0: 0x90460000  lbu         $a2, 0x0($v0)
    ctx->pc = 0x1408b0u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1408b4: 0xa0a60003  sb          $a2, 0x3($a1)
    ctx->pc = 0x1408b4u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 3), (uint8_t)GPR_U32(ctx, 6));
    // 0x1408b8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1408b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1408bc: 0xa0a20002  sb          $v0, 0x2($a1)
    ctx->pc = 0x1408bcu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1408c0: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x1408c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1408c4: 0xa0a30001  sb          $v1, 0x1($a1)
    ctx->pc = 0x1408c4u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1408c8: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1408c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1408cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1408CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1408D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1408CCu;
            // 0x1408d0: 0xa0a20000  sb          $v0, 0x0($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140814u: goto label_140814;
            case 0x140828u: goto label_140828;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1408D4u;
    // 0x1408d4: 0x0  nop
    ctx->pc = 0x1408d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6930
// Address: 0x1d6930 - 0x1d6a60
void sub_001D6930_0x1d6930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6930_0x1d6930");
#endif

    switch (ctx->pc) {
        case 0x1d6954u: goto label_1d6954;
        case 0x1d6960u: goto label_1d6960;
        default: break;
    }

    ctx->pc = 0x1d6930u;

    // 0x1d6930: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d6930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d6934: 0x4243c  dsll32      $a0, $a0, 16
    ctx->pc = 0x1d6934u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1d6938: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d6938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d693c: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1d693cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1d6940: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d6940u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d6944: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1d6944u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6948: 0x26060004  addiu       $a2, $s0, 0x4
    ctx->pc = 0x1d6948u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1d694c: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1D694Cu;
    SET_GPR_U32(ctx, 31, 0x1D6954u);
    ctx->pc = 0x1D6950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D694Cu;
            // 0x1d6950: 0x26070006  addiu       $a3, $s0, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6954u; }
        if (ctx->pc != 0x1D6954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6954u; }
        if (ctx->pc != 0x1D6954u) { return; }
    }
    ctx->pc = 0x1D6954u;
label_1d6954:
    // 0x1d6954: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d6954u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6958: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6958u;
    SET_GPR_U32(ctx, 31, 0x1D6960u);
    ctx->pc = 0x1D695Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6958u;
            // 0x1d695c: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6960u; }
        if (ctx->pc != 0x1D6960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6960u; }
        if (ctx->pc != 0x1D6960u) { return; }
    }
    ctx->pc = 0x1D6960u;
label_1d6960:
    // 0x1d6960: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6960u;
    {
        const bool branch_taken_0x1d6960 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d6960) {
            ctx->pc = 0x1D6970u;
            goto label_1d6970;
        }
    }
    ctx->pc = 0x1D6968u;
    // 0x1d6968: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1D6968u;
    {
        const bool branch_taken_0x1d6968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6968) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D6970u;
label_1d6970:
    // 0x1d6970: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1d6970u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d6974: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d6974u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d6978: 0x2c61000c  sltiu       $at, $v1, 0xC
    ctx->pc = 0x1d6978u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)12) ? 1 : 0);
    // 0x1d697c: 0x10200022  beqz        $at, . + 4 + (0x22 << 2)
    ctx->pc = 0x1D697Cu;
    {
        const bool branch_taken_0x1d697c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D697Cu;
            // 0x1d6980: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d697c) {
            ctx->pc = 0x1D6A08u;
            goto label_1d6a08;
        }
    }
    ctx->pc = 0x1D6984u;
    // 0x1d6984: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d6984u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d6988: 0x24847c00  addiu       $a0, $a0, 0x7C00
    ctx->pc = 0x1d6988u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 31744));
    // 0x1d698c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d698cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d6990: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d6990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d6994: 0x600008  jr          $v1
    ctx->pc = 0x1D6994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D69A0u: goto label_1d69a0;
            case 0x1D69A8u: goto label_1d69a8;
            case 0x1D69B8u: goto label_1d69b8;
            case 0x1D69C8u: goto label_1d69c8;
            case 0x1D69D8u: goto label_1d69d8;
            case 0x1D69E8u: goto label_1d69e8;
            case 0x1D69F8u: goto label_1d69f8;
            case 0x1D6A08u: goto label_1d6a08;
            case 0x1D6A18u: goto label_1d6a18;
            case 0x1D6A28u: goto label_1d6a28;
            case 0x1D6A38u: goto label_1d6a38;
            case 0x1D6A48u: goto label_1d6a48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D699Cu;
    // 0x1d699c: 0x0  nop
    ctx->pc = 0x1d699cu;
    // NOP
label_1d69a0:
    // 0x1d69a0: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1D69A0u;
    {
        const bool branch_taken_0x1d69a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D69A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69A0u;
            // 0x1d69a4: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69a0) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D69A8u;
label_1d69a8:
    // 0x1d69a8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d69a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d69ac: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1D69ACu;
    {
        const bool branch_taken_0x1d69ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D69B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69ACu;
            // 0x1d69b0: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69ac) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D69B4u;
    // 0x1d69b4: 0x0  nop
    ctx->pc = 0x1d69b4u;
    // NOP
label_1d69b8:
    // 0x1d69b8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d69b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d69bc: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1D69BCu;
    {
        const bool branch_taken_0x1d69bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D69C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69BCu;
            // 0x1d69c0: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69bc) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D69C4u;
    // 0x1d69c4: 0x0  nop
    ctx->pc = 0x1d69c4u;
    // NOP
label_1d69c8:
    // 0x1d69c8: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1d69c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d69cc: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1D69CCu;
    {
        const bool branch_taken_0x1d69cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D69D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69CCu;
            // 0x1d69d0: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69cc) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D69D4u;
    // 0x1d69d4: 0x0  nop
    ctx->pc = 0x1d69d4u;
    // NOP
label_1d69d8:
    // 0x1d69d8: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d69d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d69dc: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D69DCu;
    {
        const bool branch_taken_0x1d69dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D69E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69DCu;
            // 0x1d69e0: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69dc) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D69E4u;
    // 0x1d69e4: 0x0  nop
    ctx->pc = 0x1d69e4u;
    // NOP
label_1d69e8:
    // 0x1d69e8: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1d69e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d69ec: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D69ECu;
    {
        const bool branch_taken_0x1d69ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D69F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69ECu;
            // 0x1d69f0: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69ec) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D69F4u;
    // 0x1d69f4: 0x0  nop
    ctx->pc = 0x1d69f4u;
    // NOP
label_1d69f8:
    // 0x1d69f8: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1d69f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d69fc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D69FCu;
    {
        const bool branch_taken_0x1d69fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D69FCu;
            // 0x1d6a00: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d69fc) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D6A04u;
    // 0x1d6a04: 0x0  nop
    ctx->pc = 0x1d6a04u;
    // NOP
label_1d6a08:
    // 0x1d6a08: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1d6a08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1d6a0c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D6A0Cu;
    {
        const bool branch_taken_0x1d6a0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A0Cu;
            // 0x1d6a10: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6a0c) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D6A14u;
    // 0x1d6a14: 0x0  nop
    ctx->pc = 0x1d6a14u;
    // NOP
label_1d6a18:
    // 0x1d6a18: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1d6a18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d6a1c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D6A1Cu;
    {
        const bool branch_taken_0x1d6a1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A1Cu;
            // 0x1d6a20: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6a1c) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D6A24u;
    // 0x1d6a24: 0x0  nop
    ctx->pc = 0x1d6a24u;
    // NOP
label_1d6a28:
    // 0x1d6a28: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x1d6a28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d6a2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D6A2Cu;
    {
        const bool branch_taken_0x1d6a2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A2Cu;
            // 0x1d6a30: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6a2c) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D6A34u;
    // 0x1d6a34: 0x0  nop
    ctx->pc = 0x1d6a34u;
    // NOP
label_1d6a38:
    // 0x1d6a38: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1d6a38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d6a3c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D6A3Cu;
    {
        const bool branch_taken_0x1d6a3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A3Cu;
            // 0x1d6a40: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6a3c) {
            ctx->pc = 0x1D6A50u;
            goto label_1d6a50;
        }
    }
    ctx->pc = 0x1D6A44u;
    // 0x1d6a44: 0x0  nop
    ctx->pc = 0x1d6a44u;
    // NOP
label_1d6a48:
    // 0x1d6a48: 0x2403000b  addiu       $v1, $zero, 0xB
    ctx->pc = 0x1d6a48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d6a4c: 0xa6030000  sh          $v1, 0x0($s0)
    ctx->pc = 0x1d6a4cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
label_1d6a50:
    // 0x1d6a50: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d6a50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6a54: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d6a54u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6a58: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6A58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A58u;
            // 0x1d6a5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6954u: goto label_1d6954;
            case 0x1D6960u: goto label_1d6960;
            case 0x1D6970u: goto label_1d6970;
            case 0x1D69A0u: goto label_1d69a0;
            case 0x1D69A8u: goto label_1d69a8;
            case 0x1D69B8u: goto label_1d69b8;
            case 0x1D69C8u: goto label_1d69c8;
            case 0x1D69D8u: goto label_1d69d8;
            case 0x1D69E8u: goto label_1d69e8;
            case 0x1D69F8u: goto label_1d69f8;
            case 0x1D6A08u: goto label_1d6a08;
            case 0x1D6A18u: goto label_1d6a18;
            case 0x1D6A28u: goto label_1d6a28;
            case 0x1D6A38u: goto label_1d6a38;
            case 0x1D6A48u: goto label_1d6a48;
            case 0x1D6A50u: goto label_1d6a50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6A60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

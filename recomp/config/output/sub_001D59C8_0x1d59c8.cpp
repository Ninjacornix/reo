#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D59C8
// Address: 0x1d59c8 - 0x1d6118
void sub_001D59C8_0x1d59c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D59C8_0x1d59c8");
#endif

    switch (ctx->pc) {
        case 0x1d5a0cu: goto label_1d5a0c;
        case 0x1d5a60u: goto label_1d5a60;
        case 0x1d5b30u: goto label_1d5b30;
        case 0x1d5ba0u: goto label_1d5ba0;
        case 0x1d5be8u: goto label_1d5be8;
        case 0x1d5c00u: goto label_1d5c00;
        case 0x1d5c0cu: goto label_1d5c0c;
        case 0x1d5c28u: goto label_1d5c28;
        case 0x1d5c54u: goto label_1d5c54;
        case 0x1d5c70u: goto label_1d5c70;
        case 0x1d5c8cu: goto label_1d5c8c;
        case 0x1d5d00u: goto label_1d5d00;
        case 0x1d5d4cu: goto label_1d5d4c;
        case 0x1d5db0u: goto label_1d5db0;
        case 0x1d5de0u: goto label_1d5de0;
        case 0x1d5e80u: goto label_1d5e80;
        case 0x1d5ee0u: goto label_1d5ee0;
        case 0x1d5f38u: goto label_1d5f38;
        case 0x1d5f60u: goto label_1d5f60;
        case 0x1d5fb0u: goto label_1d5fb0;
        case 0x1d6028u: goto label_1d6028;
        case 0x1d60b0u: goto label_1d60b0;
        default: break;
    }

    ctx->pc = 0x1d59c8u;

    // 0x1d59c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d59c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d59cc: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d59ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d59d0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1d59d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d59d4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d59d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d59d8: 0x24502840  addiu       $s0, $v0, 0x2840
    ctx->pc = 0x1d59d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 10304));
    // 0x1d59dc: 0x8e030090  lw          $v1, 0x90($s0)
    ctx->pc = 0x1d59dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
    // 0x1d59e0: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1d59e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1d59e4: 0x2c420005  sltiu       $v0, $v0, 0x5
    ctx->pc = 0x1d59e4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x1d59e8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D59E8u;
    {
        const bool branch_taken_0x1d59e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D59ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D59E8u;
            // 0x1d59ec: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d59e8) {
            ctx->pc = 0x1D5A10u;
            goto label_1d5a10;
        }
    }
    ctx->pc = 0x1D59F0u;
    // 0x1d59f0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d59f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d59f4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d59f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d59f8: 0x24426980  addiu       $v0, $v0, 0x6980
    ctx->pc = 0x1d59f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27008));
    // 0x1d59fc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1d59fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d5a00: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1d5a00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d5a04: 0x40f809  jalr        $v0
    ctx->pc = 0x1D5A04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1D5A0Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D5A0Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D5A0Cu; }
            if (ctx->pc != 0x1D5A0Cu) { return; }
        }
        }
    }
    ctx->pc = 0x1D5A0Cu;
label_1d5a0c:
    // 0x1d5a0c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1d5a0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1d5a10:
    // 0x1d5a10: 0xae000098  sw          $zero, 0x98($s0)
    ctx->pc = 0x1d5a10u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 152), GPR_U32(ctx, 0));
    // 0x1d5a14: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1d5a14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5a18: 0xae000090  sw          $zero, 0x90($s0)
    ctx->pc = 0x1d5a18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 0));
    // 0x1d5a1c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d5a1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d5a20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1d5a20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d5a24: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5A24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A24u;
            // 0x1d5a28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5A2Cu;
    // 0x1d5a2c: 0x0  nop
    ctx->pc = 0x1d5a2cu;
    // NOP
    // 0x1d5a30: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5a30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5a34: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5a34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d5a38: 0x8c4728d8  lw          $a3, 0x28D8($v0)
    ctx->pc = 0x1d5a38u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10456)));
    // 0x1d5a3c: 0x24682980  addiu       $t0, $v1, 0x2980
    ctx->pc = 0x1d5a3cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 10624));
    // 0x1d5a40: 0x90642980  lbu         $a0, 0x2980($v1)
    ctx->pc = 0x1d5a40u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 10624)));
    // 0x1d5a44: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d5a44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5a48: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x1d5a48u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1d5a4c: 0x91020001  lbu         $v0, 0x1($t0)
    ctx->pc = 0x1d5a4cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x1d5a50: 0x1080000b  beqz        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D5A50u;
    {
        const bool branch_taken_0x1d5a50 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A50u;
            // 0x1d5a54: 0xace20004  sw          $v0, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5a50) {
            ctx->pc = 0x1D5A80u;
            goto label_1d5a80;
        }
    }
    ctx->pc = 0x1D5A58u;
    // 0x1d5a58: 0x24e60008  addiu       $a2, $a3, 0x8
    ctx->pc = 0x1d5a58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x1d5a5c: 0xa81021  addu        $v0, $a1, $t0
    ctx->pc = 0x1d5a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
label_1d5a60:
    // 0x1d5a60: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x1d5a60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1d5a64: 0x90430002  lbu         $v1, 0x2($v0)
    ctx->pc = 0x1d5a64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1d5a68: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1d5a68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1d5a6c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1d5a6cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d5a70: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1d5a70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d5a74: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1d5a74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5a78: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D5A78u;
    {
        const bool branch_taken_0x1d5a78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A78u;
            // 0x1d5a7c: 0xa81021  addu        $v0, $a1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5a78) {
            ctx->pc = 0x1D5A60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5a60;
        }
    }
    ctx->pc = 0x1D5A80u;
label_1d5a80:
    // 0x1d5a80: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A80u;
            // 0x1d5a84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5A88u;
    // 0x1d5a88: 0x27bdfe60  addiu       $sp, $sp, -0x1A0
    ctx->pc = 0x1d5a88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966880));
    // 0x1d5a8c: 0x24050038  addiu       $a1, $zero, 0x38
    ctx->pc = 0x1d5a8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1d5a90: 0xffb50170  sd          $s5, 0x170($sp)
    ctx->pc = 0x1d5a90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 368), GPR_U64(ctx, 21));
    // 0x1d5a94: 0x3c060034  lui         $a2, 0x34
    ctx->pc = 0x1d5a94u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
    // 0x1d5a98: 0xffb40160  sd          $s4, 0x160($sp)
    ctx->pc = 0x1d5a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 352), GPR_U64(ctx, 20));
    // 0x1d5a9c: 0x3c150034  lui         $s5, 0x34
    ctx->pc = 0x1d5a9cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)52 << 16));
    // 0x1d5aa0: 0xffb30150  sd          $s3, 0x150($sp)
    ctx->pc = 0x1d5aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 336), GPR_U64(ctx, 19));
    // 0x1d5aa4: 0x24d42980  addiu       $s4, $a2, 0x2980
    ctx->pc = 0x1d5aa4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), 10624));
    // 0x1d5aa8: 0xffb20140  sd          $s2, 0x140($sp)
    ctx->pc = 0x1d5aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 320), GPR_U64(ctx, 18));
    // 0x1d5aac: 0x26b32840  addiu       $s3, $s5, 0x2840
    ctx->pc = 0x1d5aacu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
    // 0x1d5ab0: 0xffb00120  sd          $s0, 0x120($sp)
    ctx->pc = 0x1d5ab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 16));
    // 0x1d5ab4: 0x240400ff  addiu       $a0, $zero, 0xFF
    ctx->pc = 0x1d5ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d5ab8: 0xffbf0190  sd          $ra, 0x190($sp)
    ctx->pc = 0x1d5ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 400), GPR_U64(ctx, 31));
    // 0x1d5abc: 0xffb60180  sd          $s6, 0x180($sp)
    ctx->pc = 0x1d5abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 384), GPR_U64(ctx, 22));
    // 0x1d5ac0: 0xffb10130  sd          $s1, 0x130($sp)
    ctx->pc = 0x1d5ac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 17));
    // 0x1d5ac4: 0x8e710098  lw          $s1, 0x98($s3)
    ctx->pc = 0x1d5ac4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 152)));
    // 0x1d5ac8: 0x8e620094  lw          $v0, 0x94($s3)
    ctx->pc = 0x1d5ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
    // 0x1d5acc: 0x8e630004  lw          $v1, 0x4($s3)
    ctx->pc = 0x1d5accu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1d5ad0: 0x451018  mult        $v0, $v0, $a1
    ctx->pc = 0x1d5ad0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1d5ad4: 0x92850001  lbu         $a1, 0x1($s4)
    ctx->pc = 0x1d5ad4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
    // 0x1d5ad8: 0x628021  addu        $s0, $v1, $v0
    ctx->pc = 0x1d5ad8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d5adc: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x1d5adcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1d5ae0: 0x10a4013c  beq         $a1, $a0, . + 4 + (0x13C << 2)
    ctx->pc = 0x1D5AE0u;
    {
        const bool branch_taken_0x1d5ae0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D5AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5AE0u;
            // 0x1d5ae4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5ae0) {
            ctx->pc = 0x1D5FD4u;
            goto label_1d5fd4;
        }
    }
    ctx->pc = 0x1D5AE8u;
    // 0x1d5ae8: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1d5ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1d5aec: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d5aecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5af0: 0x5444002d  bnel        $v0, $a0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1D5AF0u;
    {
        const bool branch_taken_0x1d5af0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x1d5af0) {
            ctx->pc = 0x1D5AF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5AF0u;
            // 0x1d5af4: 0x8e030010  lw          $v1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5BA8u;
            goto label_1d5ba8;
        }
    }
    ctx->pc = 0x1D5AF8u;
    // 0x1d5af8: 0x90c22980  lbu         $v0, 0x2980($a2)
    ctx->pc = 0x1d5af8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 10624)));
    // 0x1d5afc: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d5afcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d5b00: 0x92830001  lbu         $v1, 0x1($s4)
    ctx->pc = 0x1d5b00u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
    // 0x1d5b04: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x1d5b04u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x1d5b08: 0x92820002  lbu         $v0, 0x2($s4)
    ctx->pc = 0x1d5b08u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 2)));
    // 0x1d5b0c: 0x10600130  beqz        $v1, . + 4 + (0x130 << 2)
    ctx->pc = 0x1D5B0Cu;
    {
        const bool branch_taken_0x1d5b0c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B0Cu;
            // 0x1d5b10: 0xae220004  sw          $v0, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5b0c) {
            ctx->pc = 0x1D5FD0u;
            goto label_1d5fd0;
        }
    }
    ctx->pc = 0x1D5B14u;
    // 0x1d5b14: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d5b14u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5b18: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D5B18u;
    {
        const bool branch_taken_0x1d5b18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B18u;
            // 0x1d5b1c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5b18) {
            ctx->pc = 0x1D5B64u;
            goto label_1d5b64;
        }
    }
    ctx->pc = 0x1D5B20u;
    // 0x1d5b20: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1d5b20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5b24: 0x2630000c  addiu       $s0, $s1, 0xC
    ctx->pc = 0x1d5b24u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1d5b28: 0xd41821  addu        $v1, $a2, $s4
    ctx->pc = 0x1d5b28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 20)));
    // 0x1d5b2c: 0x0  nop
    ctx->pc = 0x1d5b2cu;
    // NOP
label_1d5b30:
    // 0x1d5b30: 0x90620004  lbu         $v0, 0x4($v1)
    ctx->pc = 0x1d5b30u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d5b34: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D5B34u;
    {
        const bool branch_taken_0x1d5b34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B34u;
            // 0x1d5b38: 0x71040  sll         $v0, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5b34) {
            ctx->pc = 0x1D5B4Cu;
            goto label_1d5b4c;
        }
    }
    ctx->pc = 0x1D5B3Cu;
    // 0x1d5b3c: 0x90630004  lbu         $v1, 0x4($v1)
    ctx->pc = 0x1d5b3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d5b40: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1d5b40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1d5b44: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d5b44u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d5b48: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1d5b48u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_1d5b4c:
    // 0x1d5b4c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d5b4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d5b50: 0xc4102a  slt         $v0, $a2, $a0
    ctx->pc = 0x1d5b50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1d5b54: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1D5B54u;
    {
        const bool branch_taken_0x1d5b54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B54u;
            // 0x1d5b58: 0xd41821  addu        $v1, $a2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5b54) {
            ctx->pc = 0x1D5B30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5b30;
        }
    }
    ctx->pc = 0x1D5B5Cu;
    // 0x1d5b5c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5B5Cu;
    {
        const bool branch_taken_0x1d5b5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B5Cu;
            // 0x1d5b60: 0xae270008  sw          $a3, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5b5c) {
            ctx->pc = 0x1D5B6Cu;
            goto label_1d5b6c;
        }
    }
    ctx->pc = 0x1D5B64u;
label_1d5b64:
    // 0x1d5b64: 0x2630000c  addiu       $s0, $s1, 0xC
    ctx->pc = 0x1d5b64u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1d5b68: 0xae270008  sw          $a3, 0x8($s1)
    ctx->pc = 0x1d5b68u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 7));
label_1d5b6c:
    // 0x1d5b6c: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D5B6Cu;
    {
        const bool branch_taken_0x1d5b6c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B6Cu;
            // 0x1d5b70: 0x26a22840  addiu       $v0, $s5, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5b6c) {
            ctx->pc = 0x1D5B84u;
            goto label_1d5b84;
        }
    }
    ctx->pc = 0x1D5B74u;
    // 0x1d5b74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d5b74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5b78: 0xa620000c  sh          $zero, 0xC($s1)
    ctx->pc = 0x1d5b78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d5b7c: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1d5b7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1d5b80: 0x26a22840  addiu       $v0, $s5, 0x2840
    ctx->pc = 0x1d5b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
label_1d5b84:
    // 0x1d5b84: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x1d5b84u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5b88: 0x8c440094  lw          $a0, 0x94($v0)
    ctx->pc = 0x1d5b88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 148)));
    // 0x1d5b8c: 0x100482d  daddu       $t1, $t0, $zero
    ctx->pc = 0x1d5b8cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5b90: 0x8e270008  lw          $a3, 0x8($s1)
    ctx->pc = 0x1d5b90u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1d5b94: 0x92250004  lbu         $a1, 0x4($s1)
    ctx->pc = 0x1d5b94u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1d5b98: 0xc075888  jal         func_1D6220
    ctx->pc = 0x1D5B98u;
    SET_GPR_U32(ctx, 31, 0x1D5BA0u);
    ctx->pc = 0x1D5B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5B98u;
            // 0x1d5b9c: 0x92260000  lbu         $a2, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6220u;
    if (runtime->hasFunction(0x1D6220u)) {
        auto targetFn = runtime->lookupFunction(0x1D6220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5BA0u; }
        if (ctx->pc != 0x1D5BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6220_0x1d6220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5BA0u; }
        if (ctx->pc != 0x1D5BA0u) { return; }
    }
    ctx->pc = 0x1D5BA0u;
label_1d5ba0:
    // 0x1d5ba0: 0x1000010c  b           . + 4 + (0x10C << 2)
    ctx->pc = 0x1D5BA0u;
    {
        const bool branch_taken_0x1d5ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BA0u;
            // 0x1d5ba4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5ba0) {
            ctx->pc = 0x1D5FD4u;
            goto label_1d5fd4;
        }
    }
    ctx->pc = 0x1D5BA8u;
label_1d5ba8:
    // 0x1d5ba8: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D5BA8u;
    {
        const bool branch_taken_0x1d5ba8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D5BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BA8u;
            // 0x1d5bac: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5ba8) {
            ctx->pc = 0x1D5BC8u;
            goto label_1d5bc8;
        }
    }
    ctx->pc = 0x1D5BB0u;
    // 0x1d5bb0: 0x14400030  bnez        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1D5BB0u;
    {
        const bool branch_taken_0x1d5bb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BB0u;
            // 0x1d5bb4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5bb0) {
            ctx->pc = 0x1D5C74u;
            goto label_1d5c74;
        }
    }
    ctx->pc = 0x1D5BB8u;
    // 0x1d5bb8: 0x5062001e  beql        $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D5BB8u;
    {
        const bool branch_taken_0x1d5bb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d5bb8) {
            ctx->pc = 0x1D5BBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BB8u;
            // 0x1d5bbc: 0x8e420004  lw          $v0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5C34u;
            goto label_1d5c34;
        }
    }
    ctx->pc = 0x1D5BC0u;
    // 0x1d5bc0: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1D5BC0u;
    {
        const bool branch_taken_0x1d5bc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d5bc0) {
            ctx->pc = 0x1D5C74u;
            goto label_1d5c74;
        }
    }
    ctx->pc = 0x1D5BC8u;
label_1d5bc8:
    // 0x1d5bc8: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x1d5bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1d5bcc: 0x8e430008  lw          $v1, 0x8($s2)
    ctx->pc = 0x1d5bccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1d5bd0: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1d5bd0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d5bd4: 0x14400027  bnez        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1D5BD4u;
    {
        const bool branch_taken_0x1d5bd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d5bd4) {
            ctx->pc = 0x1D5C74u;
            goto label_1d5c74;
        }
    }
    ctx->pc = 0x1D5BDCu;
    // 0x1d5bdc: 0xae400004  sw          $zero, 0x4($s2)
    ctx->pc = 0x1d5bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
    // 0x1d5be0: 0xc075846  jal         func_1D6118
    ctx->pc = 0x1D5BE0u;
    SET_GPR_U32(ctx, 31, 0x1D5BE8u);
    ctx->pc = 0x1D5BE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BE0u;
            // 0x1d5be4: 0x8e640094  lw          $a0, 0x94($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6118u;
    if (runtime->hasFunction(0x1D6118u)) {
        auto targetFn = runtime->lookupFunction(0x1D6118u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5BE8u; }
        if (ctx->pc != 0x1D5BE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6118_0x1d6118(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5BE8u; }
        if (ctx->pc != 0x1D5BE8u) { return; }
    }
    ctx->pc = 0x1D5BE8u;
label_1d5be8:
    // 0x1d5be8: 0x8e430008  lw          $v1, 0x8($s2)
    ctx->pc = 0x1d5be8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1d5bec: 0x28630002  slti        $v1, $v1, 0x2
    ctx->pc = 0x1d5becu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d5bf0: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D5BF0u;
    {
        const bool branch_taken_0x1d5bf0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BF0u;
            // 0x1d5bf4: 0x8e640094  lw          $a0, 0x94($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5bf0) {
            ctx->pc = 0x1D5C04u;
            goto label_1d5c04;
        }
    }
    ctx->pc = 0x1D5BF8u;
    // 0x1d5bf8: 0xc075852  jal         func_1D6148
    ctx->pc = 0x1D5BF8u;
    SET_GPR_U32(ctx, 31, 0x1D5C00u);
    ctx->pc = 0x1D5BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5BF8u;
            // 0x1d5bfc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6148u;
    if (runtime->hasFunction(0x1D6148u)) {
        auto targetFn = runtime->lookupFunction(0x1D6148u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C00u; }
        if (ctx->pc != 0x1D5C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6148_0x1d6148(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C00u; }
        if (ctx->pc != 0x1D5C00u) { return; }
    }
    ctx->pc = 0x1D5C00u;
label_1d5c00:
    // 0x1d5c00: 0x8e640094  lw          $a0, 0x94($s3)
    ctx->pc = 0x1d5c00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
label_1d5c04:
    // 0x1d5c04: 0xc075852  jal         func_1D6148
    ctx->pc = 0x1D5C04u;
    SET_GPR_U32(ctx, 31, 0x1D5C0Cu);
    ctx->pc = 0x1D5C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C04u;
            // 0x1d5c08: 0x96450010  lhu         $a1, 0x10($s2) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6148u;
    if (runtime->hasFunction(0x1D6148u)) {
        auto targetFn = runtime->lookupFunction(0x1D6148u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C0Cu; }
        if (ctx->pc != 0x1D5C0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6148_0x1d6148(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C0Cu; }
        if (ctx->pc != 0x1D5C0Cu) { return; }
    }
    ctx->pc = 0x1D5C0Cu;
label_1d5c0c:
    // 0x1d5c0c: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x1d5c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1d5c10: 0x28630002  slti        $v1, $v1, 0x2
    ctx->pc = 0x1d5c10u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d5c14: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D5C14u;
    {
        const bool branch_taken_0x1d5c14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C14u;
            // 0x1d5c18: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5c14) {
            ctx->pc = 0x1D5C2Cu;
            goto label_1d5c2c;
        }
    }
    ctx->pc = 0x1D5C1Cu;
    // 0x1d5c1c: 0x8e640094  lw          $a0, 0x94($s3)
    ctx->pc = 0x1d5c1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
    // 0x1d5c20: 0xc075852  jal         func_1D6148
    ctx->pc = 0x1D5C20u;
    SET_GPR_U32(ctx, 31, 0x1D5C28u);
    ctx->pc = 0x1D5C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C20u;
            // 0x1d5c24: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6148u;
    if (runtime->hasFunction(0x1D6148u)) {
        auto targetFn = runtime->lookupFunction(0x1D6148u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C28u; }
        if (ctx->pc != 0x1D5C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6148_0x1d6148(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C28u; }
        if (ctx->pc != 0x1D5C28u) { return; }
    }
    ctx->pc = 0x1D5C28u;
label_1d5c28:
    // 0x1d5c28: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d5c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1d5c2c:
    // 0x1d5c2c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D5C2Cu;
    {
        const bool branch_taken_0x1d5c2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C2Cu;
            // 0x1d5c30: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5c2c) {
            ctx->pc = 0x1D5C70u;
            goto label_1d5c70;
        }
    }
    ctx->pc = 0x1D5C34u;
label_1d5c34:
    // 0x1d5c34: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x1d5c34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1d5c38: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1d5c38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d5c3c: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1D5C3Cu;
    {
        const bool branch_taken_0x1d5c3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d5c3c) {
            ctx->pc = 0x1D5C74u;
            goto label_1d5c74;
        }
    }
    ctx->pc = 0x1D5C44u;
    // 0x1d5c44: 0xae400004  sw          $zero, 0x4($s2)
    ctx->pc = 0x1d5c44u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
    // 0x1d5c48: 0x96450010  lhu         $a1, 0x10($s2)
    ctx->pc = 0x1d5c48u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1d5c4c: 0xc075852  jal         func_1D6148
    ctx->pc = 0x1D5C4Cu;
    SET_GPR_U32(ctx, 31, 0x1D5C54u);
    ctx->pc = 0x1D5C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C4Cu;
            // 0x1d5c50: 0x8e640094  lw          $a0, 0x94($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6148u;
    if (runtime->hasFunction(0x1D6148u)) {
        auto targetFn = runtime->lookupFunction(0x1D6148u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C54u; }
        if (ctx->pc != 0x1D5C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6148_0x1d6148(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C54u; }
        if (ctx->pc != 0x1D5C54u) { return; }
    }
    ctx->pc = 0x1D5C54u;
label_1d5c54:
    // 0x1d5c54: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x1d5c54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1d5c58: 0x28630002  slti        $v1, $v1, 0x2
    ctx->pc = 0x1d5c58u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d5c5c: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D5C5Cu;
    {
        const bool branch_taken_0x1d5c5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d5c5c) {
            ctx->pc = 0x1D5C60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C5Cu;
            // 0x1d5c60: 0x92850001  lbu         $a1, 0x1($s4) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5C74u;
            goto label_1d5c74;
        }
    }
    ctx->pc = 0x1D5C64u;
    // 0x1d5c64: 0x8e640094  lw          $a0, 0x94($s3)
    ctx->pc = 0x1d5c64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
    // 0x1d5c68: 0xc075852  jal         func_1D6148
    ctx->pc = 0x1D5C68u;
    SET_GPR_U32(ctx, 31, 0x1D5C70u);
    ctx->pc = 0x1D5C6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C68u;
            // 0x1d5c6c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6148u;
    if (runtime->hasFunction(0x1D6148u)) {
        auto targetFn = runtime->lookupFunction(0x1D6148u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C70u; }
        if (ctx->pc != 0x1D5C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6148_0x1d6148(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C70u; }
        if (ctx->pc != 0x1D5C70u) { return; }
    }
    ctx->pc = 0x1D5C70u;
label_1d5c70:
    // 0x1d5c70: 0x92850001  lbu         $a1, 0x1($s4)
    ctx->pc = 0x1d5c70u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
label_1d5c74:
    // 0x1d5c74: 0x54a00010  bnel        $a1, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x1D5C74u;
    {
        const bool branch_taken_0x1d5c74 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d5c74) {
            ctx->pc = 0x1D5C78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C74u;
            // 0x1d5c78: 0x92830004  lbu         $v1, 0x4($s4) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5CB8u;
            goto label_1d5cb8;
        }
    }
    ctx->pc = 0x1D5C7Cu;
    // 0x1d5c7c: 0x26b02840  addiu       $s0, $s5, 0x2840
    ctx->pc = 0x1d5c7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
    // 0x1d5c80: 0x27a50110  addiu       $a1, $sp, 0x110
    ctx->pc = 0x1d5c80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 272));
    // 0x1d5c84: 0xc07586e  jal         func_1D61B8
    ctx->pc = 0x1D5C84u;
    SET_GPR_U32(ctx, 31, 0x1D5C8Cu);
    ctx->pc = 0x1D5C88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C84u;
            // 0x1d5c88: 0x8e040094  lw          $a0, 0x94($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D61B8u;
    if (runtime->hasFunction(0x1D61B8u)) {
        auto targetFn = runtime->lookupFunction(0x1D61B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C8Cu; }
        if (ctx->pc != 0x1D5C8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D61B8_0x1d61b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5C8Cu; }
        if (ctx->pc != 0x1D5C8Cu) { return; }
    }
    ctx->pc = 0x1D5C8Cu;
label_1d5c8c:
    // 0x1d5c8c: 0x544000d0  bnel        $v0, $zero, . + 4 + (0xD0 << 2)
    ctx->pc = 0x1D5C8Cu;
    {
        const bool branch_taken_0x1d5c8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d5c8c) {
            ctx->pc = 0x1D5C90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5C8Cu;
            // 0x1d5c90: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5FD0u;
            goto label_1d5fd0;
        }
    }
    ctx->pc = 0x1D5C94u;
    // 0x1d5c94: 0x97a30110  lhu         $v1, 0x110($sp)
    ctx->pc = 0x1d5c94u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x1d5c98: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d5c98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5c9c: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1d5c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1d5ca0: 0xa623000c  sh          $v1, 0xC($s1)
    ctx->pc = 0x1d5ca0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d5ca4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1d5ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1d5ca8: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d5ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d5cac: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x1d5cacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1d5cb0: 0x100000c7  b           . + 4 + (0xC7 << 2)
    ctx->pc = 0x1D5CB0u;
    {
        const bool branch_taken_0x1d5cb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5CB0u;
            // 0x1d5cb4: 0xae230004  sw          $v1, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5cb0) {
            ctx->pc = 0x1D5FD0u;
            goto label_1d5fd0;
        }
    }
    ctx->pc = 0x1D5CB8u;
label_1d5cb8:
    // 0x1d5cb8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d5cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5cbc: 0x54620005  bnel        $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D5CBCu;
    {
        const bool branch_taken_0x1d5cbc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d5cbc) {
            ctx->pc = 0x1D5CC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5CBCu;
            // 0x1d5cc0: 0x92830000  lbu         $v1, 0x0($s4) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5CD4u;
            goto label_1d5cd4;
        }
    }
    ctx->pc = 0x1D5CC4u;
    // 0x1d5cc4: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1d5cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1d5cc8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5cc8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5ccc: 0x100000c1  b           . + 4 + (0xC1 << 2)
    ctx->pc = 0x1D5CCCu;
    {
        const bool branch_taken_0x1d5ccc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5CCCu;
            // 0x1d5cd0: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5ccc) {
            ctx->pc = 0x1D5FD4u;
            goto label_1d5fd4;
        }
    }
    ctx->pc = 0x1D5CD4u;
label_1d5cd4:
    // 0x1d5cd4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d5cd4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5cd8: 0x92840001  lbu         $a0, 0x1($s4)
    ctx->pc = 0x1d5cd8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
    // 0x1d5cdc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d5cdcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5ce0: 0x92820002  lbu         $v0, 0x2($s4)
    ctx->pc = 0x1d5ce0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 2)));
    // 0x1d5ce4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1d5ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1d5ce8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1d5ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1d5cec: 0x10800012  beqz        $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D5CECu;
    {
        const bool branch_taken_0x1d5cec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5CECu;
            // 0x1d5cf0: 0xafa40008  sw          $a0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5cec) {
            ctx->pc = 0x1D5D38u;
            goto label_1d5d38;
        }
    }
    ctx->pc = 0x1D5CF4u;
    // 0x1d5cf4: 0x3c160034  lui         $s6, 0x34
    ctx->pc = 0x1d5cf4u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)52 << 16));
    // 0x1d5cf8: 0xd41821  addu        $v1, $a2, $s4
    ctx->pc = 0x1d5cf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 20)));
    // 0x1d5cfc: 0x0  nop
    ctx->pc = 0x1d5cfcu;
    // NOP
label_1d5d00:
    // 0x1d5d00: 0x90620004  lbu         $v0, 0x4($v1)
    ctx->pc = 0x1d5d00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d5d04: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D5D04u;
    {
        const bool branch_taken_0x1d5d04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D04u;
            // 0x1d5d08: 0x71040  sll         $v0, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d04) {
            ctx->pc = 0x1D5D20u;
            goto label_1d5d20;
        }
    }
    ctx->pc = 0x1D5D0Cu;
    // 0x1d5d0c: 0x90630004  lbu         $v1, 0x4($v1)
    ctx->pc = 0x1d5d0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d5d10: 0x27a5000c  addiu       $a1, $sp, 0xC
    ctx->pc = 0x1d5d10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x1d5d14: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d5d14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d5d18: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1d5d18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1d5d1c: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1d5d1cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_1d5d20:
    // 0x1d5d20: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d5d20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d5d24: 0xc4102a  slt         $v0, $a2, $a0
    ctx->pc = 0x1d5d24u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1d5d28: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1D5D28u;
    {
        const bool branch_taken_0x1d5d28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D28u;
            // 0x1d5d2c: 0xd41821  addu        $v1, $a2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d28) {
            ctx->pc = 0x1D5D00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5d00;
        }
    }
    ctx->pc = 0x1D5D30u;
    // 0x1d5d30: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5D30u;
    {
        const bool branch_taken_0x1d5d30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D30u;
            // 0x1d5d34: 0xafa70008  sw          $a3, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d30) {
            ctx->pc = 0x1D5D40u;
            goto label_1d5d40;
        }
    }
    ctx->pc = 0x1D5D38u;
label_1d5d38:
    // 0x1d5d38: 0x3c160034  lui         $s6, 0x34
    ctx->pc = 0x1d5d38u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)52 << 16));
    // 0x1d5d3c: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x1d5d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
label_1d5d40:
    // 0x1d5d40: 0x26b02840  addiu       $s0, $s5, 0x2840
    ctx->pc = 0x1d5d40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
    // 0x1d5d44: 0xc075846  jal         func_1D6118
    ctx->pc = 0x1D5D44u;
    SET_GPR_U32(ctx, 31, 0x1D5D4Cu);
    ctx->pc = 0x1D5D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D44u;
            // 0x1d5d48: 0x8e040094  lw          $a0, 0x94($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6118u;
    if (runtime->hasFunction(0x1D6118u)) {
        auto targetFn = runtime->lookupFunction(0x1D6118u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5D4Cu; }
        if (ctx->pc != 0x1D5D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6118_0x1d6118(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5D4Cu; }
        if (ctx->pc != 0x1D5D4Cu) { return; }
    }
    ctx->pc = 0x1D5D4Cu;
label_1d5d4c:
    // 0x1d5d4c: 0x97a3000c  lhu         $v1, 0xC($sp)
    ctx->pc = 0x1d5d4cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1d5d50: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D5D50u;
    {
        const bool branch_taken_0x1d5d50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D50u;
            // 0x1d5d54: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d50) {
            ctx->pc = 0x1D5D64u;
            goto label_1d5d64;
        }
    }
    ctx->pc = 0x1D5D58u;
    // 0x1d5d58: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1d5d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1d5d5c: 0x5062000b  beql        $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D5D5Cu;
    {
        const bool branch_taken_0x1d5d5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d5d5c) {
            ctx->pc = 0x1D5D60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D5Cu;
            // 0x1d5d60: 0x96020014  lhu         $v0, 0x14($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5D8Cu;
            goto label_1d5d8c;
        }
    }
    ctx->pc = 0x1D5D64u;
label_1d5d64:
    // 0x1d5d64: 0xa620000c  sh          $zero, 0xC($s1)
    ctx->pc = 0x1d5d64u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d5d68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d5d68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5d6c: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1d5d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1d5d70: 0xa6400010  sh          $zero, 0x10($s2)
    ctx->pc = 0x1d5d70u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 16), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d5d74: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1d5d74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d5d78: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d5d78u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d5d7c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1d5d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1d5d80: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1d5d80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1d5d84: 0x10000086  b           . + 4 + (0x86 << 2)
    ctx->pc = 0x1D5D84u;
    {
        const bool branch_taken_0x1d5d84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D84u;
            // 0x1d5d88: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d84) {
            ctx->pc = 0x1D5FA0u;
            goto label_1d5fa0;
        }
    }
    ctx->pc = 0x1D5D8Cu;
label_1d5d8c:
    // 0x1d5d8c: 0x10400037  beqz        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x1D5D8Cu;
    {
        const bool branch_taken_0x1d5d8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D8Cu;
            // 0x1d5d90: 0x8fa40008  lw          $a0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d8c) {
            ctx->pc = 0x1D5E6Cu;
            goto label_1d5e6c;
        }
    }
    ctx->pc = 0x1D5D94u;
    // 0x1d5d94: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1d5d94u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5d98: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d5d98u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5d9c: 0x18800030  blez        $a0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1D5D9Cu;
    {
        const bool branch_taken_0x1d5d9c = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1D5DA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5D9Cu;
            // 0x1d5da0: 0x80602d  daddu       $t4, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5d9c) {
            ctx->pc = 0x1D5E60u;
            goto label_1d5e60;
        }
    }
    ctx->pc = 0x1D5DA4u;
    // 0x1d5da4: 0x2630000c  addiu       $s0, $s1, 0xC
    ctx->pc = 0x1d5da4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1d5da8: 0x26a32840  addiu       $v1, $s5, 0x2840
    ctx->pc = 0x1d5da8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
    // 0x1d5dac: 0x0  nop
    ctx->pc = 0x1d5dacu;
    // NOP
label_1d5db0:
    // 0x1d5db0: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x1d5db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1d5db4: 0x18400017  blez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1D5DB4u;
    {
        const bool branch_taken_0x1d5db4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D5DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5DB4u;
            // 0x1d5db8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5db4) {
            ctx->pc = 0x1D5E14u;
            goto label_1d5e14;
        }
    }
    ctx->pc = 0x1D5DBCu;
    // 0x1d5dbc: 0x27a5000c  addiu       $a1, $sp, 0xC
    ctx->pc = 0x1d5dbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x1d5dc0: 0x64840  sll         $t1, $a2, 1
    ctx->pc = 0x1d5dc0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1d5dc4: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1d5dc4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5dc8: 0x94620014  lhu         $v0, 0x14($v1)
    ctx->pc = 0x1d5dc8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x1d5dcc: 0x1491821  addu        $v1, $t2, $t1
    ctx->pc = 0x1d5dccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x1d5dd0: 0x94640000  lhu         $a0, 0x0($v1)
    ctx->pc = 0x1d5dd0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d5dd4: 0x1082000f  beq         $a0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D5DD4u;
    {
        const bool branch_taken_0x1d5dd4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D5DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5DD4u;
            // 0x1d5dd8: 0x24c80001  addiu       $t0, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5dd4) {
            ctx->pc = 0x1D5E14u;
            goto label_1d5e14;
        }
    }
    ctx->pc = 0x1D5DDCu;
    // 0x1d5ddc: 0x26a52840  addiu       $a1, $s5, 0x2840
    ctx->pc = 0x1d5ddcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
label_1d5de0:
    // 0x1d5de0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d5de0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d5de4: 0x8ca20010  lw          $v0, 0x10($a1)
    ctx->pc = 0x1d5de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1d5de8: 0xe2102a  slt         $v0, $a3, $v0
    ctx->pc = 0x1d5de8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5dec: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D5DECu;
    {
        const bool branch_taken_0x1d5dec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5DECu;
            // 0x1d5df0: 0x71840  sll         $v1, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5dec) {
            ctx->pc = 0x1D5E18u;
            goto label_1d5e18;
        }
    }
    ctx->pc = 0x1D5DF4u;
    // 0x1d5df4: 0x1492021  addu        $a0, $t2, $t1
    ctx->pc = 0x1d5df4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x1d5df8: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1d5df8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d5dfc: 0x94850000  lhu         $a1, 0x0($a0)
    ctx->pc = 0x1d5dfcu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d5e00: 0x94620014  lhu         $v0, 0x14($v1)
    ctx->pc = 0x1d5e00u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x1d5e04: 0x14a2fff6  bne         $a1, $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1D5E04u;
    {
        const bool branch_taken_0x1d5e04 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D5E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E04u;
            // 0x1d5e08: 0x26a52840  addiu       $a1, $s5, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e04) {
            ctx->pc = 0x1D5DE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5de0;
        }
    }
    ctx->pc = 0x1D5E0Cu;
    // 0x1d5e0c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5E0Cu;
    {
        const bool branch_taken_0x1d5e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E0Cu;
            // 0x1d5e10: 0x26a22840  addiu       $v0, $s5, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e0c) {
            ctx->pc = 0x1D5E1Cu;
            goto label_1d5e1c;
        }
    }
    ctx->pc = 0x1D5E14u;
label_1d5e14:
    // 0x1d5e14: 0x24c80001  addiu       $t0, $a2, 0x1
    ctx->pc = 0x1d5e14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1d5e18:
    // 0x1d5e18: 0x26a22840  addiu       $v0, $s5, 0x2840
    ctx->pc = 0x1d5e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
label_1d5e1c:
    // 0x1d5e1c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1d5e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1d5e20: 0x54e3000a  bnel        $a3, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1D5E20u;
    {
        const bool branch_taken_0x1d5e20 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        if (branch_taken_0x1d5e20) {
            ctx->pc = 0x1D5E24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E20u;
            // 0x1d5e24: 0x100302d  daddu       $a2, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5E4Cu;
            goto label_1d5e4c;
        }
    }
    ctx->pc = 0x1D5E28u;
    // 0x1d5e28: 0x62040  sll         $a0, $a2, 1
    ctx->pc = 0x1d5e28u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1d5e2c: 0x27a2000c  addiu       $v0, $sp, 0xC
    ctx->pc = 0x1d5e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x1d5e30: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1d5e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1d5e34: 0xb1840  sll         $v1, $t3, 1
    ctx->pc = 0x1d5e34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 11), 1));
    // 0x1d5e38: 0x94440000  lhu         $a0, 0x0($v0)
    ctx->pc = 0x1d5e38u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d5e3c: 0x2031821  addu        $v1, $s0, $v1
    ctx->pc = 0x1d5e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1d5e40: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x1d5e40u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1d5e44: 0xa4640000  sh          $a0, 0x0($v1)
    ctx->pc = 0x1d5e44u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1d5e48: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x1d5e48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1d5e4c:
    // 0x1d5e4c: 0xcc102a  slt         $v0, $a2, $t4
    ctx->pc = 0x1d5e4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 12)) ? 1 : 0);
    // 0x1d5e50: 0x1440ffd7  bnez        $v0, . + 4 + (-0x29 << 2)
    ctx->pc = 0x1D5E50u;
    {
        const bool branch_taken_0x1d5e50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E50u;
            // 0x1d5e54: 0x26a32840  addiu       $v1, $s5, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e50) {
            ctx->pc = 0x1D5DB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5db0;
        }
    }
    ctx->pc = 0x1D5E58u;
    // 0x1d5e58: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1D5E58u;
    {
        const bool branch_taken_0x1d5e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E58u;
            // 0x1d5e5c: 0xae2b0008  sw          $t3, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e58) {
            ctx->pc = 0x1D5EB0u;
            goto label_1d5eb0;
        }
    }
    ctx->pc = 0x1D5E60u;
label_1d5e60:
    // 0x1d5e60: 0x2630000c  addiu       $s0, $s1, 0xC
    ctx->pc = 0x1d5e60u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1d5e64: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1D5E64u;
    {
        const bool branch_taken_0x1d5e64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E64u;
            // 0x1d5e68: 0xae2b0008  sw          $t3, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e64) {
            ctx->pc = 0x1D5EB0u;
            goto label_1d5eb0;
        }
    }
    ctx->pc = 0x1D5E6Cu;
label_1d5e6c:
    // 0x1d5e6c: 0x8fa70008  lw          $a3, 0x8($sp)
    ctx->pc = 0x1d5e6cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1d5e70: 0x18e0000d  blez        $a3, . + 4 + (0xD << 2)
    ctx->pc = 0x1D5E70u;
    {
        const bool branch_taken_0x1d5e70 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x1D5E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E70u;
            // 0x1d5e74: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e70) {
            ctx->pc = 0x1D5EA8u;
            goto label_1d5ea8;
        }
    }
    ctx->pc = 0x1D5E78u;
    // 0x1d5e78: 0x2630000c  addiu       $s0, $s1, 0xC
    ctx->pc = 0x1d5e78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1d5e7c: 0x27a5000c  addiu       $a1, $sp, 0xC
    ctx->pc = 0x1d5e7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
label_1d5e80:
    // 0x1d5e80: 0x61040  sll         $v0, $a2, 1
    ctx->pc = 0x1d5e80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1d5e84: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1d5e84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1d5e88: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d5e88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d5e8c: 0x94640000  lhu         $a0, 0x0($v1)
    ctx->pc = 0x1d5e8cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d5e90: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1d5e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1d5e94: 0xc7182a  slt         $v1, $a2, $a3
    ctx->pc = 0x1d5e94u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1d5e98: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D5E98u;
    {
        const bool branch_taken_0x1d5e98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5E98u;
            // 0x1d5e9c: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5e98) {
            ctx->pc = 0x1D5E80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5e80;
        }
    }
    ctx->pc = 0x1D5EA0u;
    // 0x1d5ea0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5EA0u;
    {
        const bool branch_taken_0x1d5ea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5EA0u;
            // 0x1d5ea4: 0xae260008  sw          $a2, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5ea0) {
            ctx->pc = 0x1D5EB0u;
            goto label_1d5eb0;
        }
    }
    ctx->pc = 0x1D5EA8u;
label_1d5ea8:
    // 0x1d5ea8: 0x2630000c  addiu       $s0, $s1, 0xC
    ctx->pc = 0x1d5ea8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x1d5eac: 0xae260008  sw          $a2, 0x8($s1)
    ctx->pc = 0x1d5eacu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 6));
label_1d5eb0:
    // 0x1d5eb0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1d5eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d5eb4: 0x26b32840  addiu       $s3, $s5, 0x2840
    ctx->pc = 0x1d5eb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), 10304));
    // 0x1d5eb8: 0x8e270008  lw          $a3, 0x8($s1)
    ctx->pc = 0x1d5eb8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1d5ebc: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x1d5ebcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5ec0: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d5ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d5ec4: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1d5ec4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5ec8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1d5ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1d5ecc: 0x92260000  lbu         $a2, 0x0($s1)
    ctx->pc = 0x1d5eccu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d5ed0: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1d5ed0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1d5ed4: 0x8e640094  lw          $a0, 0x94($s3)
    ctx->pc = 0x1d5ed4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
    // 0x1d5ed8: 0xc075888  jal         func_1D6220
    ctx->pc = 0x1D5ED8u;
    SET_GPR_U32(ctx, 31, 0x1D5EE0u);
    ctx->pc = 0x1D5EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5ED8u;
            // 0x1d5edc: 0x92250004  lbu         $a1, 0x4($s1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6220u;
    if (runtime->hasFunction(0x1D6220u)) {
        auto targetFn = runtime->lookupFunction(0x1D6220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5EE0u; }
        if (ctx->pc != 0x1D5EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6220_0x1d6220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5EE0u; }
        if (ctx->pc != 0x1D5EE0u) { return; }
    }
    ctx->pc = 0x1D5EE0u;
label_1d5ee0:
    // 0x1d5ee0: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1d5ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1d5ee4: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D5EE4u;
    {
        const bool branch_taken_0x1d5ee4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D5EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5EE4u;
            // 0x1d5ee8: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5ee4) {
            ctx->pc = 0x1D5F18u;
            goto label_1d5f18;
        }
    }
    ctx->pc = 0x1D5EECu;
    // 0x1d5eec: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x1d5eecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1d5ef0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1d5ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1d5ef4: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1d5ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1d5ef8: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1d5ef8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d5efc: 0x18800028  blez        $a0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1D5EFCu;
    {
        const bool branch_taken_0x1d5efc = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1D5F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5EFCu;
            // 0x1d5f00: 0xa6430010  sh          $v1, 0x10($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5efc) {
            ctx->pc = 0x1D5FA0u;
            goto label_1d5fa0;
        }
    }
    ctx->pc = 0x1D5F04u;
    // 0x1d5f04: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x1d5f04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1d5f08: 0x18400025  blez        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1D5F08u;
    {
        const bool branch_taken_0x1d5f08 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D5F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F08u;
            // 0x1d5f0c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5f08) {
            ctx->pc = 0x1D5FA0u;
            goto label_1d5fa0;
        }
    }
    ctx->pc = 0x1D5F10u;
    // 0x1d5f10: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1D5F10u;
    {
        const bool branch_taken_0x1d5f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F10u;
            // 0x1d5f14: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5f10) {
            ctx->pc = 0x1D5FA0u;
            goto label_1d5fa0;
        }
    }
    ctx->pc = 0x1D5F18u;
label_1d5f18:
    // 0x1d5f18: 0x27b00090  addiu       $s0, $sp, 0x90
    ctx->pc = 0x1d5f18u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1d5f1c: 0x93a50004  lbu         $a1, 0x4($sp)
    ctx->pc = 0x1d5f1cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1d5f20: 0x8e640094  lw          $a0, 0x94($s3)
    ctx->pc = 0x1d5f20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 148)));
    // 0x1d5f24: 0x37a8000c  ori         $t0, $sp, 0xC
    ctx->pc = 0x1d5f24u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)12);
    // 0x1d5f28: 0x93a60000  lbu         $a2, 0x0($sp)
    ctx->pc = 0x1d5f28u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d5f2c: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1d5f2cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5f30: 0xc075888  jal         func_1D6220
    ctx->pc = 0x1D5F30u;
    SET_GPR_U32(ctx, 31, 0x1D5F38u);
    ctx->pc = 0x1D5F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F30u;
            // 0x1d5f34: 0x8fa70008  lw          $a3, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6220u;
    if (runtime->hasFunction(0x1D6220u)) {
        auto targetFn = runtime->lookupFunction(0x1D6220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5F38u; }
        if (ctx->pc != 0x1D5F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6220_0x1d6220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5F38u; }
        if (ctx->pc != 0x1D5F38u) { return; }
    }
    ctx->pc = 0x1D5F38u;
label_1d5f38:
    // 0x1d5f38: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x1d5f38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1d5f3c: 0x1880000e  blez        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x1D5F3Cu;
    {
        const bool branch_taken_0x1d5f3c = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1D5F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F3Cu;
            // 0x1d5f40: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5f3c) {
            ctx->pc = 0x1D5F78u;
            goto label_1d5f78;
        }
    }
    ctx->pc = 0x1D5F44u;
    // 0x1d5f44: 0x97a20090  lhu         $v0, 0x90($sp)
    ctx->pc = 0x1d5f44u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1d5f48: 0x96430010  lhu         $v1, 0x10($s2)
    ctx->pc = 0x1d5f48u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1d5f4c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1D5F4Cu;
    {
        const bool branch_taken_0x1d5f4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D5F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F4Cu;
            // 0x1d5f50: 0x60282d  daddu       $a1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5f4c) {
            ctx->pc = 0x1D5F78u;
            goto label_1d5f78;
        }
    }
    ctx->pc = 0x1D5F54u;
    // 0x1d5f54: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1d5f54u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5f58: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1d5f58u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5f5c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d5f5cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1d5f60:
    // 0x1d5f60: 0xc3102a  slt         $v0, $a2, $v1
    ctx->pc = 0x1d5f60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d5f64: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D5F64u;
    {
        const bool branch_taken_0x1d5f64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F64u;
            // 0x1d5f68: 0x25290002  addiu       $t1, $t1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5f64) {
            ctx->pc = 0x1D5F78u;
            goto label_1d5f78;
        }
    }
    ctx->pc = 0x1D5F6Cu;
    // 0x1d5f6c: 0x95220000  lhu         $v0, 0x0($t1)
    ctx->pc = 0x1d5f6cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1d5f70: 0x5445fffb  bnel        $v0, $a1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1D5F70u;
    {
        const bool branch_taken_0x1d5f70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x1d5f70) {
            ctx->pc = 0x1D5F74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F70u;
            // 0x1d5f74: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D5F60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5f60;
        }
    }
    ctx->pc = 0x1D5F78u;
label_1d5f78:
    // 0x1d5f78: 0x14c4000a  bne         $a2, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D5F78u;
    {
        const bool branch_taken_0x1d5f78 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        ctx->pc = 0x1D5F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5F78u;
            // 0x1d5f7c: 0x26c52848  addiu       $a1, $s6, 0x2848 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), 10312));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5f78) {
            ctx->pc = 0x1D5FA4u;
            goto label_1d5fa4;
        }
    }
    ctx->pc = 0x1D5F80u;
    // 0x1d5f80: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1d5f80u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1d5f84: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d5f84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5f88: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1d5f88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1d5f8c: 0xa620000c  sh          $zero, 0xC($s1)
    ctx->pc = 0x1d5f8cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d5f90: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1d5f90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d5f94: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d5f94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d5f98: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1d5f98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1d5f9c: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1d5f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
label_1d5fa0:
    // 0x1d5fa0: 0x26c52848  addiu       $a1, $s6, 0x2848
    ctx->pc = 0x1d5fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), 10312));
label_1d5fa4:
    // 0x1d5fa4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1d5fa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5fa8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d5fa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5fac: 0x0  nop
    ctx->pc = 0x1d5facu;
    // NOP
label_1d5fb0:
    // 0x1d5fb0: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x1d5fb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d5fb4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d5fb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d5fb8: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1d5fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1d5fbc: 0x2cc20088  sltiu       $v0, $a2, 0x88
    ctx->pc = 0x1d5fbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)136) ? 1 : 0);
    // 0x1d5fc0: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x1d5fc0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d5fc4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1d5fc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1d5fc8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D5FC8u;
    {
        const bool branch_taken_0x1d5fc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d5fc8) {
            ctx->pc = 0x1D5FB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5fb0;
        }
    }
    ctx->pc = 0x1D5FD0u;
label_1d5fd0:
    // 0x1d5fd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5fd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5fd4:
    // 0x1d5fd4: 0xdfbf0190  ld          $ra, 0x190($sp)
    ctx->pc = 0x1d5fd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 400)));
    // 0x1d5fd8: 0xdfb60180  ld          $s6, 0x180($sp)
    ctx->pc = 0x1d5fd8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x1d5fdc: 0xdfb50170  ld          $s5, 0x170($sp)
    ctx->pc = 0x1d5fdcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x1d5fe0: 0xdfb40160  ld          $s4, 0x160($sp)
    ctx->pc = 0x1d5fe0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x1d5fe4: 0xdfb30150  ld          $s3, 0x150($sp)
    ctx->pc = 0x1d5fe4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 336)));
    // 0x1d5fe8: 0xdfb20140  ld          $s2, 0x140($sp)
    ctx->pc = 0x1d5fe8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x1d5fec: 0xdfb10130  ld          $s1, 0x130($sp)
    ctx->pc = 0x1d5fecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1d5ff0: 0xdfb00120  ld          $s0, 0x120($sp)
    ctx->pc = 0x1d5ff0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x1d5ff4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5FF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5FF4u;
            // 0x1d5ff8: 0x27bd01a0  addiu       $sp, $sp, 0x1A0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 416));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5FFCu;
    // 0x1d5ffc: 0x0  nop
    ctx->pc = 0x1d5ffcu;
    // NOP
    // 0x1d6000: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d6000u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d6004: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d6004u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d6008: 0x24442980  addiu       $a0, $v0, 0x2980
    ctx->pc = 0x1d6008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 10624));
    // 0x1d600c: 0x90820006  lbu         $v0, 0x6($a0)
    ctx->pc = 0x1d600cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1d6010: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6010u;
    {
        const bool branch_taken_0x1d6010 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6010u;
            // 0x1d6014: 0x8c6328d8  lw          $v1, 0x28D8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10456)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6010) {
            ctx->pc = 0x1D6020u;
            goto label_1d6020;
        }
    }
    ctx->pc = 0x1D6018u;
    // 0x1d6018: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D601Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6018u;
            // 0x1d601c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6020u;
label_1d6020:
    // 0x1d6020: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1d6020u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d6024: 0x0  nop
    ctx->pc = 0x1d6024u;
    // NOP
label_1d6028:
    // 0x1d6028: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1d6028u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d602c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1d602cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1d6030: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1d6030u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1d6034: 0xa0620000  sb          $v0, 0x0($v1)
    ctx->pc = 0x1d6034u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d6038: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d6038u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d603c: 0x4a1fffa  bgez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D603Cu;
    {
        const bool branch_taken_0x1d603c = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1d603c) {
            ctx->pc = 0x1D6028u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d6028;
        }
    }
    ctx->pc = 0x1D6044u;
    // 0x1d6044: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6044u;
            // 0x1d6048: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D604Cu;
    // 0x1d604c: 0x0  nop
    ctx->pc = 0x1d604cu;
    // NOP
    // 0x1d6050: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d6050u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d6054: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d6054u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d6058: 0x90432981  lbu         $v1, 0x2981($v0)
    ctx->pc = 0x1d6058u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 10625)));
    // 0x1d605c: 0x90a42941  lbu         $a0, 0x2941($a1)
    ctx->pc = 0x1d605cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10561)));
    // 0x1d6060: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d6060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6064: 0x641826  xor         $v1, $v1, $a0
    ctx->pc = 0x1d6064u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 4));
    // 0x1d6068: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D606Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6068u;
            // 0x1d606c: 0x3100a  movz        $v0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6070u;
    // 0x1d6070: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d6070u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d6074: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d6074u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d6078: 0x90432981  lbu         $v1, 0x2981($v0)
    ctx->pc = 0x1d6078u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 10625)));
    // 0x1d607c: 0x90a42941  lbu         $a0, 0x2941($a1)
    ctx->pc = 0x1d607cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10561)));
    // 0x1d6080: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d6080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6084: 0x641826  xor         $v1, $v1, $a0
    ctx->pc = 0x1d6084u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 4));
    // 0x1d6088: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D608Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6088u;
            // 0x1d608c: 0x3100a  movz        $v0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6090u;
    // 0x1d6090: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d6090u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d6094: 0x8ca22840  lw          $v0, 0x2840($a1)
    ctx->pc = 0x1d6094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
    // 0x1d6098: 0x1840001a  blez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1D6098u;
    {
        const bool branch_taken_0x1d6098 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D609Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6098u;
            // 0x1d609c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6098) {
            ctx->pc = 0x1D6104u;
            goto label_1d6104;
        }
    }
    ctx->pc = 0x1D60A0u;
    // 0x1d60a0: 0x24a22840  addiu       $v0, $a1, 0x2840
    ctx->pc = 0x1d60a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 10304));
    // 0x1d60a4: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1d60a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d60a8: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1d60a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1d60ac: 0x0  nop
    ctx->pc = 0x1d60acu;
    // NOP
label_1d60b0:
    // 0x1d60b0: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x1d60b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1d60b4: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D60B4u;
    {
        const bool branch_taken_0x1d60b4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D60B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60B4u;
            // 0x1d60b8: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60b4) {
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60BCu;
    // 0x1d60bc: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x1d60bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1d60c0: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D60C0u;
    {
        const bool branch_taken_0x1d60c0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D60C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60C0u;
            // 0x1d60c4: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60c0) {
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60C8u;
    // 0x1d60c8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1d60c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d60cc: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D60CCu;
    {
        const bool branch_taken_0x1d60cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d60cc) {
            ctx->pc = 0x1D60D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60CCu;
            // 0x1d60d0: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60D4u;
    // 0x1d60d4: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D60D4u;
    {
        const bool branch_taken_0x1d60d4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1D60D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60D4u;
            // 0x1d60d8: 0x28420003  slti        $v0, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60d4) {
            ctx->pc = 0x1D60F0u;
            goto label_1d60f0;
        }
    }
    ctx->pc = 0x1D60DCu;
    // 0x1d60dc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D60DCu;
    {
        const bool branch_taken_0x1d60dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D60E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60DCu;
            // 0x1d60e0: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60dc) {
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60E4u;
    // 0x1d60e4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1d60e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d60e8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d60e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d60ec: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1d60ecu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
label_1d60f0:
    // 0x1d60f0: 0x8ca22840  lw          $v0, 0x2840($a1)
    ctx->pc = 0x1d60f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
label_1d60f4:
    // 0x1d60f4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1d60f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1d60f8: 0x82102a  slt         $v0, $a0, $v0
    ctx->pc = 0x1d60f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d60fc: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1D60FCu;
    {
        const bool branch_taken_0x1d60fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D6100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60FCu;
            // 0x1d6100: 0x24630038  addiu       $v1, $v1, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60fc) {
            ctx->pc = 0x1D60B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d60b0;
        }
    }
    ctx->pc = 0x1D6104u;
label_1d6104:
    // 0x1d6104: 0xf  sync
    ctx->pc = 0x1d6104u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1d6108: 0x42000038  ei
    ctx->pc = 0x1d6108u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1d610c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D610Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D610Cu;
            // 0x1d6110: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A0Cu: goto label_1d5a0c;
            case 0x1D5A10u: goto label_1d5a10;
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            case 0x1D5B30u: goto label_1d5b30;
            case 0x1D5B4Cu: goto label_1d5b4c;
            case 0x1D5B64u: goto label_1d5b64;
            case 0x1D5B6Cu: goto label_1d5b6c;
            case 0x1D5B84u: goto label_1d5b84;
            case 0x1D5BA0u: goto label_1d5ba0;
            case 0x1D5BA8u: goto label_1d5ba8;
            case 0x1D5BC8u: goto label_1d5bc8;
            case 0x1D5BE8u: goto label_1d5be8;
            case 0x1D5C00u: goto label_1d5c00;
            case 0x1D5C04u: goto label_1d5c04;
            case 0x1D5C0Cu: goto label_1d5c0c;
            case 0x1D5C28u: goto label_1d5c28;
            case 0x1D5C2Cu: goto label_1d5c2c;
            case 0x1D5C34u: goto label_1d5c34;
            case 0x1D5C54u: goto label_1d5c54;
            case 0x1D5C70u: goto label_1d5c70;
            case 0x1D5C74u: goto label_1d5c74;
            case 0x1D5C8Cu: goto label_1d5c8c;
            case 0x1D5CB8u: goto label_1d5cb8;
            case 0x1D5CD4u: goto label_1d5cd4;
            case 0x1D5D00u: goto label_1d5d00;
            case 0x1D5D20u: goto label_1d5d20;
            case 0x1D5D38u: goto label_1d5d38;
            case 0x1D5D40u: goto label_1d5d40;
            case 0x1D5D4Cu: goto label_1d5d4c;
            case 0x1D5D64u: goto label_1d5d64;
            case 0x1D5D8Cu: goto label_1d5d8c;
            case 0x1D5DB0u: goto label_1d5db0;
            case 0x1D5DE0u: goto label_1d5de0;
            case 0x1D5E14u: goto label_1d5e14;
            case 0x1D5E18u: goto label_1d5e18;
            case 0x1D5E1Cu: goto label_1d5e1c;
            case 0x1D5E4Cu: goto label_1d5e4c;
            case 0x1D5E60u: goto label_1d5e60;
            case 0x1D5E6Cu: goto label_1d5e6c;
            case 0x1D5E80u: goto label_1d5e80;
            case 0x1D5EA8u: goto label_1d5ea8;
            case 0x1D5EB0u: goto label_1d5eb0;
            case 0x1D5EE0u: goto label_1d5ee0;
            case 0x1D5F18u: goto label_1d5f18;
            case 0x1D5F38u: goto label_1d5f38;
            case 0x1D5F60u: goto label_1d5f60;
            case 0x1D5F78u: goto label_1d5f78;
            case 0x1D5FA0u: goto label_1d5fa0;
            case 0x1D5FA4u: goto label_1d5fa4;
            case 0x1D5FB0u: goto label_1d5fb0;
            case 0x1D5FD0u: goto label_1d5fd0;
            case 0x1D5FD4u: goto label_1d5fd4;
            case 0x1D6020u: goto label_1d6020;
            case 0x1D6028u: goto label_1d6028;
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6114u;
    // 0x1d6114: 0x0  nop
    ctx->pc = 0x1d6114u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

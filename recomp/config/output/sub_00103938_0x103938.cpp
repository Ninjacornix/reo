#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103938
// Address: 0x103938 - 0x103a48
void sub_00103938_0x103938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103938_0x103938");
#endif

    switch (ctx->pc) {
        case 0x10394cu: goto label_10394c;
        case 0x1039d8u: goto label_1039d8;
        case 0x103a18u: goto label_103a18;
        default: break;
    }

    ctx->pc = 0x103938u;

    // 0x103938: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x103938u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10393c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10393cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103940: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x103940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x103944: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x103944u;
    SET_GPR_U32(ctx, 31, 0x10394Cu);
    ctx->pc = 0x103948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103944u;
            // 0x103948: 0xa62818  mult        $a1, $a1, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10394Cu; }
        if (ctx->pc != 0x10394Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10394Cu; }
        if (ctx->pc != 0x10394Cu) { return; }
    }
    ctx->pc = 0x10394Cu;
label_10394c:
    // 0x10394c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10394cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103950: 0x12000022  beqz        $s0, . + 4 + (0x22 << 2)
    ctx->pc = 0x103950u;
    {
        const bool branch_taken_0x103950 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x103954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103950u;
            // 0x103954: 0x2403fffc  addiu       $v1, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103950) {
            ctx->pc = 0x1039DCu;
            goto label_1039dc;
        }
    }
    ctx->pc = 0x103958u;
    // 0x103958: 0x8e02fffc  lw          $v0, -0x4($s0)
    ctx->pc = 0x103958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967292)));
    // 0x10395c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10395cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x103960: 0x2447fffc  addiu       $a3, $v0, -0x4
    ctx->pc = 0x103960u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x103964: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x103964u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103968: 0x2ce20025  sltiu       $v0, $a3, 0x25
    ctx->pc = 0x103968u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)37) ? 1 : 0);
    // 0x10396c: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x10396cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103970: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x103970u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103974: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x103974u;
    {
        const bool branch_taken_0x103974 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x103978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103974u;
            // 0x103978: 0x2ce80014  sltiu       $t0, $a3, 0x14 (Delay Slot)
        SET_GPR_U64(ctx, 8, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x103974) {
            ctx->pc = 0x1039D0u;
            goto label_1039d0;
        }
    }
    ctx->pc = 0x10397Cu;
    // 0x10397c: 0x1500000e  bnez        $t0, . + 4 + (0xE << 2)
    ctx->pc = 0x10397Cu;
    {
        const bool branch_taken_0x10397c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x103980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10397Cu;
            // 0x103980: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10397c) {
            ctx->pc = 0x1039B8u;
            goto label_1039b8;
        }
    }
    ctx->pc = 0x103984u;
    // 0x103984: 0x2ce2001c  sltiu       $v0, $a3, 0x1C
    ctx->pc = 0x103984u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)28) ? 1 : 0);
    // 0x103988: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x103988u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x10398c: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x10398cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x103990: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x103990u;
    {
        const bool branch_taken_0x103990 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x103994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103990u;
            // 0x103994: 0x26030008  addiu       $v1, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103990) {
            ctx->pc = 0x1039B8u;
            goto label_1039b8;
        }
    }
    ctx->pc = 0x103998u;
    // 0x103998: 0x2ce20024  sltiu       $v0, $a3, 0x24
    ctx->pc = 0x103998u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)36) ? 1 : 0);
    // 0x10399c: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x10399cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1039a0: 0x26030010  addiu       $v1, $s0, 0x10
    ctx->pc = 0x1039a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1039a4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1039A4u;
    {
        const bool branch_taken_0x1039a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1039A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1039A4u;
            // 0x1039a8: 0xae00000c  sw          $zero, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1039a4) {
            ctx->pc = 0x1039B8u;
            goto label_1039b8;
        }
    }
    ctx->pc = 0x1039ACu;
    // 0x1039ac: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1039acu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1039b0: 0x26030018  addiu       $v1, $s0, 0x18
    ctx->pc = 0x1039b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x1039b4: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1039b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
label_1039b8:
    // 0x1039b8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1039b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1039bc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1039bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1039c0: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1039c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1039c4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1039C4u;
    {
        const bool branch_taken_0x1039c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1039C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1039C4u;
            // 0x1039c8: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1039c4) {
            ctx->pc = 0x1039D8u;
            goto label_1039d8;
        }
    }
    ctx->pc = 0x1039CCu;
    // 0x1039cc: 0x0  nop
    ctx->pc = 0x1039ccu;
    // NOP
label_1039d0:
    // 0x1039d0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1039D0u;
    SET_GPR_U32(ctx, 31, 0x1039D8u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1039D8u; }
        if (ctx->pc != 0x1039D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1039D8u; }
        if (ctx->pc != 0x1039D8u) { return; }
    }
    ctx->pc = 0x1039D8u;
label_1039d8:
    // 0x1039d8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1039d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1039dc:
    // 0x1039dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1039dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1039e0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1039e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1039e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1039E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1039E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1039E4u;
            // 0x1039e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10394Cu: goto label_10394c;
            case 0x1039B8u: goto label_1039b8;
            case 0x1039D0u: goto label_1039d0;
            case 0x1039D8u: goto label_1039d8;
            case 0x1039DCu: goto label_1039dc;
            case 0x103A18u: goto label_103a18;
            case 0x103A34u: goto label_103a34;
            case 0x103A38u: goto label_103a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1039ECu;
    // 0x1039ec: 0x0  nop
    ctx->pc = 0x1039ecu;
    // NOP
    // 0x1039f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1039f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1039f4: 0x3c020037  lui         $v0, 0x37
    ctx->pc = 0x1039f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)55 << 16));
    // 0x1039f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1039f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1039fc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1039fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a00: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x103a00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x103a04: 0x2451f0dc  addiu       $s1, $v0, -0xF24
    ctx->pc = 0x103a04u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963420));
    // 0x103a08: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x103a08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a0c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x103a0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x103a10: 0xc045342  jal         func_114D08
    ctx->pc = 0x103A10u;
    SET_GPR_U32(ctx, 31, 0x103A18u);
    ctx->pc = 0x103A14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103A10u;
            // 0x103a14: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114D08u;
    if (runtime->hasFunction(0x114D08u)) {
        auto targetFn = runtime->lookupFunction(0x114D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103A18u; }
        if (ctx->pc != 0x103A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114D08_0x114d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103A18u; }
        if (ctx->pc != 0x103A18u) { return; }
    }
    ctx->pc = 0x103A18u;
label_103a18:
    // 0x103a18: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x103a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a1c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x103a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x103a20: 0x54830005  bnel        $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x103A20u;
    {
        const bool branch_taken_0x103a20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x103a20) {
            ctx->pc = 0x103A24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103A20u;
            // 0x103a24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103A38u;
            goto label_103a38;
        }
    }
    ctx->pc = 0x103A28u;
    // 0x103a28: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x103a28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x103a2c: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x103A2Cu;
    {
        const bool branch_taken_0x103a2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x103a2c) {
            ctx->pc = 0x103A30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103A2Cu;
            // 0x103a30: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103A34u;
            goto label_103a34;
        }
    }
    ctx->pc = 0x103A34u;
label_103a34:
    // 0x103a34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_103a38:
    // 0x103a38: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x103a38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x103a3c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x103a3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103a40: 0x3e00008  jr          $ra
    ctx->pc = 0x103A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103A40u;
            // 0x103a44: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10394Cu: goto label_10394c;
            case 0x1039B8u: goto label_1039b8;
            case 0x1039D0u: goto label_1039d0;
            case 0x1039D8u: goto label_1039d8;
            case 0x1039DCu: goto label_1039dc;
            case 0x103A18u: goto label_103a18;
            case 0x103A34u: goto label_103a34;
            case 0x103A38u: goto label_103a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103A48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

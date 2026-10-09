#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113C98
// Address: 0x113c98 - 0x113d80
void sub_00113C98_0x113c98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113C98_0x113c98");
#endif

    switch (ctx->pc) {
        case 0x113cb0u: goto label_113cb0;
        case 0x113cf8u: goto label_113cf8;
        case 0x113d1cu: goto label_113d1c;
        default: break;
    }

    ctx->pc = 0x113c98u;

    // 0x113c98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x113c98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x113c9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x113c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113ca0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x113ca0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113ca4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x113ca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x113ca8: 0xc044f08  jal         func_113C20
    ctx->pc = 0x113CA8u;
    SET_GPR_U32(ctx, 31, 0x113CB0u);
    ctx->pc = 0x113CACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113CA8u;
            // 0x113cac: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113C20u;
    if (runtime->hasFunction(0x113C20u)) {
        auto targetFn = runtime->lookupFunction(0x113C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113CB0u; }
        if (ctx->pc != 0x113CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C20_0x113c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113CB0u; }
        if (ctx->pc != 0x113CB0u) { return; }
    }
    ctx->pc = 0x113CB0u;
label_113cb0:
    // 0x113cb0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113cb4: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x113cb4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x113cb8: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x113cb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x113cbc: 0x34c6b430  ori         $a2, $a2, 0xB430
    ctx->pc = 0x113cbcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)46128);
    // 0x113cc0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x113cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113cc4: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x113cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x113cc8: 0x3484b420  ori         $a0, $a0, 0xB420
    ctx->pc = 0x113cc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46112);
    // 0x113ccc: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x113cccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x113cd0: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x113cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x113cd4: 0x34a5b400  ori         $a1, $a1, 0xB400
    ctx->pc = 0x113cd4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)46080);
    // 0x113cd8: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x113cd8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x113cdc: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x113cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113ce0: 0x34e72010  ori         $a3, $a3, 0x2010
    ctx->pc = 0x113ce0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)8208);
    // 0x113ce4: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x113ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x113ce8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x113ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x113cec: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x113cecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x113cf0: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x113cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x113cf4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x113cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_113cf8:
    // 0x113cf8: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x113cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x113cfc: 0x304200f0  andi        $v0, $v0, 0xF0
    ctx->pc = 0x113cfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)240);
    // 0x113d00: 0x0  nop
    ctx->pc = 0x113d00u;
    // NOP
    // 0x113d04: 0x0  nop
    ctx->pc = 0x113d04u;
    // NOP
    // 0x113d08: 0x0  nop
    ctx->pc = 0x113d08u;
    // NOP
    // 0x113d0c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113D0Cu;
    {
        const bool branch_taken_0x113d0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x113d0c) {
            ctx->pc = 0x113CF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113cf8;
        }
    }
    ctx->pc = 0x113D14u;
    // 0x113d14: 0xc044eea  jal         func_113BA8
    ctx->pc = 0x113D14u;
    SET_GPR_U32(ctx, 31, 0x113D1Cu);
    ctx->pc = 0x113D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113D14u;
            // 0x113d18: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113BA8u;
    if (runtime->hasFunction(0x113BA8u)) {
        auto targetFn = runtime->lookupFunction(0x113BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113D1Cu; }
        if (ctx->pc != 0x113D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113BA8_0x113ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113D1Cu; }
        if (ctx->pc != 0x113D1Cu) { return; }
    }
    ctx->pc = 0x113D1Cu;
label_113d1c:
    // 0x113d1c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113d20: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x113d20u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x113d24: 0x3442b010  ori         $v0, $v0, 0xB010
    ctx->pc = 0x113d24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45072);
    // 0x113d28: 0x34e7b020  ori         $a3, $a3, 0xB020
    ctx->pc = 0x113d28u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)45088);
    // 0x113d2c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x113d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113d30: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x113d30u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x113d34: 0x34a5b000  ori         $a1, $a1, 0xB000
    ctx->pc = 0x113d34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)45056);
    // 0x113d38: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x113d38u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x113d3c: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x113d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x113d40: 0x34c62020  ori         $a2, $a2, 0x2020
    ctx->pc = 0x113d40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)8224);
    // 0x113d44: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x113d44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x113d48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x113d48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x113d4c: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x113d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x113d50: 0x34842010  ori         $a0, $a0, 0x2010
    ctx->pc = 0x113d50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8208);
    // 0x113d54: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x113d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x113d58: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x113d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x113d5c: 0xae020018  sw          $v0, 0x18($s0)
    ctx->pc = 0x113d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
    // 0x113d60: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x113d60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113d64: 0xae03001c  sw          $v1, 0x1C($s0)
    ctx->pc = 0x113d64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
    // 0x113d68: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x113d68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x113d6c: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x113d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x113d70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x113d70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113d74: 0x3e00008  jr          $ra
    ctx->pc = 0x113D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113D74u;
            // 0x113d78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113CB0u: goto label_113cb0;
            case 0x113CF8u: goto label_113cf8;
            case 0x113D1Cu: goto label_113d1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113D7Cu;
    // 0x113d7c: 0x0  nop
    ctx->pc = 0x113d7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

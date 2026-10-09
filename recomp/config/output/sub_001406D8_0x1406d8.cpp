#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001406D8
// Address: 0x1406d8 - 0x140764
void sub_001406D8_0x1406d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001406D8_0x1406d8");
#endif

    switch (ctx->pc) {
        case 0x140710u: goto label_140710;
        default: break;
    }

    ctx->pc = 0x1406d8u;

    // 0x1406d8: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1406d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1406dc: 0x2ca50004  sltiu       $a1, $a1, 0x4
    ctx->pc = 0x1406dcu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1406e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1406e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1406e4: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1406e4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1406e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1406e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1406ec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1406ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1406f0: 0x14a00009  bnez        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1406F0u;
    {
        const bool branch_taken_0x1406f0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1406F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1406F0u;
            // 0x1406f4: 0xace00000  sw          $zero, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1406f0) {
            ctx->pc = 0x140718u;
            goto label_140718;
        }
    }
    ctx->pc = 0x1406F8u;
    // 0x1406f8: 0x8d020028  lw          $v0, 0x28($t0)
    ctx->pc = 0x1406f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 40)));
    // 0x1406fc: 0x50400016  beql        $v0, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x1406FCu;
    {
        const bool branch_taken_0x1406fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1406fc) {
            ctx->pc = 0x140700u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1406FCu;
            // 0x140700: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140704u;
    // 0x140704: 0x8d04002c  lw          $a0, 0x2C($t0)
    ctx->pc = 0x140704u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 44)));
    // 0x140708: 0x40f809  jalr        $v0
    ctx->pc = 0x140708u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140710u);
        ctx->pc = 0x14070Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140708u;
            // 0x14070c: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140710u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140710u; }
            if (ctx->pc != 0x140710u) { return; }
        }
        }
    }
    ctx->pc = 0x140710u;
label_140710:
    // 0x140710: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x140710u;
    {
        const bool branch_taken_0x140710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140710u;
            // 0x140714: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140710) {
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140718u;
label_140718:
    // 0x140718: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x140718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x14071c: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x14071Cu;
    {
        const bool branch_taken_0x14071c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x140720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14071Cu;
            // 0x140720: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14071c) {
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140724u;
    // 0x140724: 0x6862000f  ldl         $v0, 0xF($v1)
    ctx->pc = 0x140724u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x140728: 0x6c620008  ldr         $v0, 0x8($v1)
    ctx->pc = 0x140728u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x14072c: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x14072cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140730: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x140730u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140734: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x140734u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140738: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x140738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x14073c: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x14073cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x140740: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x140740u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x140744: 0x663026  xor         $a2, $v1, $a2
    ctx->pc = 0x140744u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 6));
    // 0x140748: 0x81030005  lb          $v1, 0x5($t0)
    ctx->pc = 0x140748u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 5)));
    // 0x14074c: 0x10640002  beq         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x14074Cu;
    {
        const bool branch_taken_0x14074c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x140750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14074Cu;
            // 0x140750: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x14074c) {
            ctx->pc = 0x140758u;
            goto label_140758;
        }
    }
    ctx->pc = 0x140754u;
    // 0x140754: 0x2cc20001  sltiu       $v0, $a2, 0x1
    ctx->pc = 0x140754u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_140758:
    // 0x140758: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14075c: 0x3e00008  jr          $ra
    ctx->pc = 0x14075Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14075Cu;
            // 0x140760: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140710u: goto label_140710;
            case 0x140718u: goto label_140718;
            case 0x140758u: goto label_140758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140764u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

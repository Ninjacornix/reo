#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168BA8
// Address: 0x168ba8 - 0x168c70
void sub_00168BA8_0x168ba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168BA8_0x168ba8");
#endif

    switch (ctx->pc) {
        case 0x168bd0u: goto label_168bd0;
        default: break;
    }

    ctx->pc = 0x168ba8u;

    // 0x168ba8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x168ba8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x168bac: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x168bacu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168bb0: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x168bb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168bb4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x168bb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168bb8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x168bb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x168bbc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x168bbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168bc0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x168bc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168bc4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x168bc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x168bc8: 0xc05a31c  jal         func_168C70
    ctx->pc = 0x168BC8u;
    SET_GPR_U32(ctx, 31, 0x168BD0u);
    ctx->pc = 0x168BCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168BC8u;
            // 0x168bcc: 0x60302d  daddu       $a2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168C70u;
    if (runtime->hasFunction(0x168C70u)) {
        auto targetFn = runtime->lookupFunction(0x168C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168BD0u; }
        if (ctx->pc != 0x168BD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168C70_0x168c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168BD0u; }
        if (ctx->pc != 0x168BD0u) { return; }
    }
    ctx->pc = 0x168BD0u;
label_168bd0:
    // 0x168bd0: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x168BD0u;
    {
        const bool branch_taken_0x168bd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168BD0u;
            // 0x168bd4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168bd0) {
            ctx->pc = 0x168C5Cu;
            goto label_168c5c;
        }
    }
    ctx->pc = 0x168BD8u;
    // 0x168bd8: 0x93a20000  lbu         $v0, 0x0($sp)
    ctx->pc = 0x168bd8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168bdc: 0x14430013  bne         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x168BDCu;
    {
        const bool branch_taken_0x168bdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x168BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168BDCu;
            // 0x168be0: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168bdc) {
            ctx->pc = 0x168C2Cu;
            goto label_168c2c;
        }
    }
    ctx->pc = 0x168BE4u;
    // 0x168be4: 0x93a20002  lbu         $v0, 0x2($sp)
    ctx->pc = 0x168be4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x168be8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x168BE8u;
    {
        const bool branch_taken_0x168be8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168BE8u;
            // 0x168bec: 0x93a20003  lbu         $v0, 0x3($sp) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168be8) {
            ctx->pc = 0x168C28u;
            goto label_168c28;
        }
    }
    ctx->pc = 0x168BF0u;
    // 0x168bf0: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x168BF0u;
    {
        const bool branch_taken_0x168bf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168BF0u;
            // 0x168bf4: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168bf0) {
            ctx->pc = 0x168C2Cu;
            goto label_168c2c;
        }
    }
    ctx->pc = 0x168BF8u;
    // 0x168bf8: 0x93a20006  lbu         $v0, 0x6($sp)
    ctx->pc = 0x168bf8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 6)));
    // 0x168bfc: 0x93a40003  lbu         $a0, 0x3($sp)
    ctx->pc = 0x168bfcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 3)));
    // 0x168c00: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x168c00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x168c04: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x168c04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x168c08: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x168c08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x168c0c: 0x90630660  lbu         $v1, 0x660($v1)
    ctx->pc = 0x168c0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1632)));
    // 0x168c10: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x168c10u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x168c14: 0xa2030028  sb          $v1, 0x28($s0)
    ctx->pc = 0x168c14u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 40), (uint8_t)GPR_U32(ctx, 3));
    // 0x168c18: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x168c18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x168c1c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x168c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x168c20: 0x8c420670  lw          $v0, 0x670($v0)
    ctx->pc = 0x168c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1648)));
    // 0x168c24: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x168c24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
label_168c28:
    // 0x168c28: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x168c28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
label_168c2c:
    // 0x168c2c: 0x2446ef70  addiu       $a2, $v0, -0x1090
    ctx->pc = 0x168c2cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963056));
    // 0x168c30: 0x6ba30007  ldl         $v1, 0x7($sp)
    ctx->pc = 0x168c30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x168c34: 0x6fa30000  ldr         $v1, 0x0($sp)
    ctx->pc = 0x168c34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x168c38: 0x83a40008  lb          $a0, 0x8($sp)
    ctx->pc = 0x168c38u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x168c3c: 0x83a50009  lb          $a1, 0x9($sp)
    ctx->pc = 0x168c3cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 9)));
    // 0x168c40: 0xb0c30007  sdl         $v1, 0x7($a2)
    ctx->pc = 0x168c40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x168c44: 0xb4c30000  sdr         $v1, 0x0($a2)
    ctx->pc = 0x168c44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x168c48: 0xa0c40008  sb          $a0, 0x8($a2)
    ctx->pc = 0x168c48u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 8), (uint8_t)GPR_U32(ctx, 4));
    // 0x168c4c: 0xa0c50009  sb          $a1, 0x9($a2)
    ctx->pc = 0x168c4cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 9), (uint8_t)GPR_U32(ctx, 5));
    // 0x168c50: 0x83a3000a  lb          $v1, 0xA($sp)
    ctx->pc = 0x168c50u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 10)));
    // 0x168c54: 0xa0c3000a  sb          $v1, 0xA($a2)
    ctx->pc = 0x168c54u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 10), (uint8_t)GPR_U32(ctx, 3));
    // 0x168c58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x168c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_168c5c:
    // 0x168c5c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x168c5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168c60: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x168c60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168c64: 0x3e00008  jr          $ra
    ctx->pc = 0x168C64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168C64u;
            // 0x168c68: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168BD0u: goto label_168bd0;
            case 0x168C28u: goto label_168c28;
            case 0x168C2Cu: goto label_168c2c;
            case 0x168C5Cu: goto label_168c5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168C6Cu;
    // 0x168c6c: 0x0  nop
    ctx->pc = 0x168c6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

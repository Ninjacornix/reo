#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155BC8
// Address: 0x155bc8 - 0x155de0
void sub_00155BC8_0x155bc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155BC8_0x155bc8");
#endif

    switch (ctx->pc) {
        case 0x155be8u: goto label_155be8;
        case 0x155cb4u: goto label_155cb4;
        case 0x155cbcu: goto label_155cbc;
        case 0x155cecu: goto label_155cec;
        case 0x155d78u: goto label_155d78;
        case 0x155d90u: goto label_155d90;
        default: break;
    }

    ctx->pc = 0x155bc8u;

    // 0x155bc8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155bcc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x155bccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155bd0: 0x24424c10  addiu       $v0, $v0, 0x4C10
    ctx->pc = 0x155bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
    // 0x155bd4: 0x8c450040  lw          $a1, 0x40($v0)
    ctx->pc = 0x155bd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x155bd8: 0x18a0000c  blez        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x155BD8u;
    {
        const bool branch_taken_0x155bd8 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x155BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155BD8u;
            // 0x155bdc: 0x8c440044  lw          $a0, 0x44($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155bd8) {
            ctx->pc = 0x155C0Cu;
            goto label_155c0c;
        }
    }
    ctx->pc = 0x155BE0u;
    // 0x155be0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x155be0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155be4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x155be4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_155be8:
    // 0x155be8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x155be8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155bec: 0x10670008  beq         $v1, $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x155BECu;
    {
        const bool branch_taken_0x155bec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 7));
        ctx->pc = 0x155BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155BECu;
            // 0x155bf0: 0x248406a0  addiu       $a0, $a0, 0x6A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155bec) {
            ctx->pc = 0x155C10u;
            goto label_155c10;
        }
    }
    ctx->pc = 0x155BF4u;
    // 0x155bf4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x155bf4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x155bf8: 0xc5102a  slt         $v0, $a2, $a1
    ctx->pc = 0x155bf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x155bfc: 0x0  nop
    ctx->pc = 0x155bfcu;
    // NOP
    // 0x155c00: 0x0  nop
    ctx->pc = 0x155c00u;
    // NOP
    // 0x155c04: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x155C04u;
    {
        const bool branch_taken_0x155c04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x155c04) {
            ctx->pc = 0x155C08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x155C04u;
            // 0x155c08: 0x8c830000  lw          $v1, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x155BE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155be8;
        }
    }
    ctx->pc = 0x155C0Cu;
label_155c0c:
    // 0x155c0c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x155c0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_155c10:
    // 0x155c10: 0x3e00008  jr          $ra
    ctx->pc = 0x155C10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BE8u: goto label_155be8;
            case 0x155C0Cu: goto label_155c0c;
            case 0x155C10u: goto label_155c10;
            case 0x155CB4u: goto label_155cb4;
            case 0x155CBCu: goto label_155cbc;
            case 0x155CECu: goto label_155cec;
            case 0x155D10u: goto label_155d10;
            case 0x155D68u: goto label_155d68;
            case 0x155D78u: goto label_155d78;
            case 0x155D88u: goto label_155d88;
            case 0x155D90u: goto label_155d90;
            case 0x155DB8u: goto label_155db8;
            case 0x155DBCu: goto label_155dbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155C18u;
    // 0x155c18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155c18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155c1c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155c20: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x155c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155c24: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x155c24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155c28: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x155c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x155c2c: 0x24474c10  addiu       $a3, $v0, 0x4C10
    ctx->pc = 0x155c2cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
    // 0x155c30: 0x68e30007  ldl         $v1, 0x7($a3)
    ctx->pc = 0x155c30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x155c34: 0x6ce30000  ldr         $v1, 0x0($a3)
    ctx->pc = 0x155c34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x155c38: 0x68e5000f  ldl         $a1, 0xF($a3)
    ctx->pc = 0x155c38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x155c3c: 0x6ce50008  ldr         $a1, 0x8($a3)
    ctx->pc = 0x155c3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x155c40: 0x68e60017  ldl         $a2, 0x17($a3)
    ctx->pc = 0x155c40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x155c44: 0x6ce60010  ldr         $a2, 0x10($a3)
    ctx->pc = 0x155c44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x155c48: 0xb203001f  sdl         $v1, 0x1F($s0)
    ctx->pc = 0x155c48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c4c: 0xb6030018  sdr         $v1, 0x18($s0)
    ctx->pc = 0x155c4cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c50: 0xb2050027  sdl         $a1, 0x27($s0)
    ctx->pc = 0x155c50u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c54: 0xb6050020  sdr         $a1, 0x20($s0)
    ctx->pc = 0x155c54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c58: 0xb206002f  sdl         $a2, 0x2F($s0)
    ctx->pc = 0x155c58u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c5c: 0xb6060028  sdr         $a2, 0x28($s0)
    ctx->pc = 0x155c5cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c60: 0x68e3001f  ldl         $v1, 0x1F($a3)
    ctx->pc = 0x155c60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x155c64: 0x6ce30018  ldr         $v1, 0x18($a3)
    ctx->pc = 0x155c64u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x155c68: 0x68e50027  ldl         $a1, 0x27($a3)
    ctx->pc = 0x155c68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x155c6c: 0x6ce50020  ldr         $a1, 0x20($a3)
    ctx->pc = 0x155c6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x155c70: 0x68e6002f  ldl         $a2, 0x2F($a3)
    ctx->pc = 0x155c70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x155c74: 0x6ce60028  ldr         $a2, 0x28($a3)
    ctx->pc = 0x155c74u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x155c78: 0xb2030037  sdl         $v1, 0x37($s0)
    ctx->pc = 0x155c78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c7c: 0xb6030030  sdr         $v1, 0x30($s0)
    ctx->pc = 0x155c7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c80: 0xb205003f  sdl         $a1, 0x3F($s0)
    ctx->pc = 0x155c80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c84: 0xb6050038  sdr         $a1, 0x38($s0)
    ctx->pc = 0x155c84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c88: 0xb2060047  sdl         $a2, 0x47($s0)
    ctx->pc = 0x155c88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 71); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c8c: 0xb6060040  sdr         $a2, 0x40($s0)
    ctx->pc = 0x155c8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 64); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155c90: 0x68e30037  ldl         $v1, 0x37($a3)
    ctx->pc = 0x155c90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x155c94: 0x6ce30030  ldr         $v1, 0x30($a3)
    ctx->pc = 0x155c94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x155c98: 0x68e5003f  ldl         $a1, 0x3F($a3)
    ctx->pc = 0x155c98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x155c9c: 0x6ce50038  ldr         $a1, 0x38($a3)
    ctx->pc = 0x155c9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x155ca0: 0xb203004f  sdl         $v1, 0x4F($s0)
    ctx->pc = 0x155ca0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 79); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155ca4: 0xb6030048  sdr         $v1, 0x48($s0)
    ctx->pc = 0x155ca4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 72); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155ca8: 0xb2050057  sdl         $a1, 0x57($s0)
    ctx->pc = 0x155ca8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 87); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x155cac: 0xc05429e  jal         func_150A78
    ctx->pc = 0x155CACu;
    SET_GPR_U32(ctx, 31, 0x155CB4u);
    ctx->pc = 0x155CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155CACu;
            // 0x155cb0: 0xb6050050  sdr         $a1, 0x50($s0) (Delay Slot)
        { uint32_t addr = ADD32(GPR_U32(ctx, 16), 80); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x150A78u;
    if (runtime->hasFunction(0x150A78u)) {
        auto targetFn = runtime->lookupFunction(0x150A78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CB4u; }
        if (ctx->pc != 0x155CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150A78_0x150a78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CB4u; }
        if (ctx->pc != 0x155CB4u) { return; }
    }
    ctx->pc = 0x155CB4u;
label_155cb4:
    // 0x155cb4: 0xc0556ca  jal         func_155B28
    ctx->pc = 0x155CB4u;
    SET_GPR_U32(ctx, 31, 0x155CBCu);
    ctx->pc = 0x155CB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155CB4u;
            // 0x155cb8: 0x26040058  addiu       $a0, $s0, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 88));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155B28u;
    if (runtime->hasFunction(0x155B28u)) {
        auto targetFn = runtime->lookupFunction(0x155B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CBCu; }
        if (ctx->pc != 0x155CBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155B28_0x155b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CBCu; }
        if (ctx->pc != 0x155CBCu) { return; }
    }
    ctx->pc = 0x155CBCu;
label_155cbc:
    // 0x155cbc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x155cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x155cc0: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x155cc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x155cc4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x155cc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155cc8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x155cc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155ccc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155cccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155cd0: 0x3e00008  jr          $ra
    ctx->pc = 0x155CD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155CD0u;
            // 0x155cd4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BE8u: goto label_155be8;
            case 0x155C0Cu: goto label_155c0c;
            case 0x155C10u: goto label_155c10;
            case 0x155CB4u: goto label_155cb4;
            case 0x155CBCu: goto label_155cbc;
            case 0x155CECu: goto label_155cec;
            case 0x155D10u: goto label_155d10;
            case 0x155D68u: goto label_155d68;
            case 0x155D78u: goto label_155d78;
            case 0x155D88u: goto label_155d88;
            case 0x155D90u: goto label_155d90;
            case 0x155DB8u: goto label_155db8;
            case 0x155DBCu: goto label_155dbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155CD8u;
    // 0x155cd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155cd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155cdc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x155cdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155ce0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x155ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x155ce4: 0xc05578e  jal         func_155E38
    ctx->pc = 0x155CE4u;
    SET_GPR_U32(ctx, 31, 0x155CECu);
    ctx->pc = 0x155CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155CE4u;
            // 0x155ce8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CECu; }
        if (ctx->pc != 0x155CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CECu; }
        if (ctx->pc != 0x155CECu) { return; }
    }
    ctx->pc = 0x155CECu;
label_155cec:
    // 0x155cec: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x155cecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x155cf0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x155cf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155cf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x155CF4u;
    {
        const bool branch_taken_0x155cf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x155CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155CF4u;
            // 0x155cf8: 0x34a50201  ori         $a1, $a1, 0x201 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)513);
        ctx->in_delay_slot = false;
        if (branch_taken_0x155cf4) {
            ctx->pc = 0x155D10u;
            goto label_155d10;
        }
    }
    ctx->pc = 0x155CFCu;
    // 0x155cfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155d00: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x155d00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155d04: 0x805419c  j           func_150670
    ctx->pc = 0x155D04u;
    ctx->pc = 0x155D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155D04u;
            // 0x155d08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155D0Cu;
    // 0x155d0c: 0x0  nop
    ctx->pc = 0x155d0cu;
    // NOP
label_155d10:
    // 0x155d10: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x155d10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155d14: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x155d14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155d18: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x155d18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x155d1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155d1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155d20: 0x3e00008  jr          $ra
    ctx->pc = 0x155D20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D20u;
            // 0x155d24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BE8u: goto label_155be8;
            case 0x155C0Cu: goto label_155c0c;
            case 0x155C10u: goto label_155c10;
            case 0x155CB4u: goto label_155cb4;
            case 0x155CBCu: goto label_155cbc;
            case 0x155CECu: goto label_155cec;
            case 0x155D10u: goto label_155d10;
            case 0x155D68u: goto label_155d68;
            case 0x155D78u: goto label_155d78;
            case 0x155D88u: goto label_155d88;
            case 0x155D90u: goto label_155d90;
            case 0x155DB8u: goto label_155db8;
            case 0x155DBCu: goto label_155dbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155D28u;
    // 0x155d28: 0x3e00008  jr          $ra
    ctx->pc = 0x155D28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BE8u: goto label_155be8;
            case 0x155C0Cu: goto label_155c0c;
            case 0x155C10u: goto label_155c10;
            case 0x155CB4u: goto label_155cb4;
            case 0x155CBCu: goto label_155cbc;
            case 0x155CECu: goto label_155cec;
            case 0x155D10u: goto label_155d10;
            case 0x155D68u: goto label_155d68;
            case 0x155D78u: goto label_155d78;
            case 0x155D88u: goto label_155d88;
            case 0x155D90u: goto label_155d90;
            case 0x155DB8u: goto label_155db8;
            case 0x155DBCu: goto label_155dbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155D30u;
    // 0x155d30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x155d30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x155d34: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x155d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x155d38: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x155d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x155d3c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x155d3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155d40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x155d40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155d44: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x155d44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155d48: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x155d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x155d4c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x155d4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155d50: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x155d50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x155d54: 0x16420004  bne         $s2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x155D54u;
    {
        const bool branch_taken_0x155d54 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x155D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D54u;
            // 0x155d58: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d54) {
            ctx->pc = 0x155D68u;
            goto label_155d68;
        }
    }
    ctx->pc = 0x155D5Cu;
    // 0x155d5c: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x155D5Cu;
    {
        const bool branch_taken_0x155d5c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x155D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D5Cu;
            // 0x155d60: 0x3c020015  lui         $v0, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d5c) {
            ctx->pc = 0x155D68u;
            goto label_155d68;
        }
    }
    ctx->pc = 0x155D64u;
    // 0x155d64: 0x24510318  addiu       $s1, $v0, 0x318
    ctx->pc = 0x155d64u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 792));
label_155d68:
    // 0x155d68: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x155D68u;
    {
        const bool branch_taken_0x155d68 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x155d68) {
            ctx->pc = 0x155D88u;
            goto label_155d88;
        }
    }
    ctx->pc = 0x155D70u;
    // 0x155d70: 0xc055778  jal         func_155DE0
    ctx->pc = 0x155D70u;
    SET_GPR_U32(ctx, 31, 0x155D78u);
    ctx->pc = 0x155D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155D70u;
            // 0x155d74: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155DE0u;
    if (runtime->hasFunction(0x155DE0u)) {
        auto targetFn = runtime->lookupFunction(0x155DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D78u; }
        if (ctx->pc != 0x155D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155DE0_0x155de0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D78u; }
        if (ctx->pc != 0x155D78u) { return; }
    }
    ctx->pc = 0x155D78u;
label_155d78:
    // 0x155d78: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155d7c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x155D7Cu;
    {
        const bool branch_taken_0x155d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D7Cu;
            // 0x155d80: 0x24444c10  addiu       $a0, $v0, 0x4C10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d7c) {
            ctx->pc = 0x155DBCu;
            goto label_155dbc;
        }
    }
    ctx->pc = 0x155D84u;
    // 0x155d84: 0x0  nop
    ctx->pc = 0x155d84u;
    // NOP
label_155d88:
    // 0x155d88: 0xc05578e  jal         func_155E38
    ctx->pc = 0x155D88u;
    SET_GPR_U32(ctx, 31, 0x155D90u);
    ctx->pc = 0x155D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155D88u;
            // 0x155d8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D90u; }
        if (ctx->pc != 0x155D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D90u; }
        if (ctx->pc != 0x155D90u) { return; }
    }
    ctx->pc = 0x155D90u;
label_155d90:
    // 0x155d90: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x155d90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x155d94: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x155D94u;
    {
        const bool branch_taken_0x155d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x155D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D94u;
            // 0x155d98: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d94) {
            ctx->pc = 0x155DB8u;
            goto label_155db8;
        }
    }
    ctx->pc = 0x155D9Cu;
    // 0x155d9c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155d9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155da0: 0x34a50202  ori         $a1, $a1, 0x202
    ctx->pc = 0x155da0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)514);
    // 0x155da4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155da4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155da8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155da8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155dac: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x155dacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x155db0: 0x805419c  j           func_150670
    ctx->pc = 0x155DB0u;
    ctx->pc = 0x155DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155DB0u;
            // 0x155db4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155DB8u;
label_155db8:
    // 0x155db8: 0x26040018  addiu       $a0, $s0, 0x18
    ctx->pc = 0x155db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
label_155dbc:
    // 0x155dbc: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x155dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x155dc0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155dc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155dc4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x155dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x155dc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155dc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155dcc: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x155dccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x155dd0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x155dd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x155dd4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155dd4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155dd8: 0x3e00008  jr          $ra
    ctx->pc = 0x155DD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155DD8u;
            // 0x155ddc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155BE8u: goto label_155be8;
            case 0x155C0Cu: goto label_155c0c;
            case 0x155C10u: goto label_155c10;
            case 0x155CB4u: goto label_155cb4;
            case 0x155CBCu: goto label_155cbc;
            case 0x155CECu: goto label_155cec;
            case 0x155D10u: goto label_155d10;
            case 0x155D68u: goto label_155d68;
            case 0x155D78u: goto label_155d78;
            case 0x155D88u: goto label_155d88;
            case 0x155D90u: goto label_155d90;
            case 0x155DB8u: goto label_155db8;
            case 0x155DBCu: goto label_155dbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155DE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

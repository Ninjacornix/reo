#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186F68
// Address: 0x186f68 - 0x187330
void sub_00186F68_0x186f68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186F68_0x186f68");
#endif

    switch (ctx->pc) {
        case 0x187030u: goto label_187030;
        case 0x187094u: goto label_187094;
        case 0x187148u: goto label_187148;
        case 0x1871acu: goto label_1871ac;
        case 0x187208u: goto label_187208;
        case 0x187254u: goto label_187254;
        case 0x1872b4u: goto label_1872b4;
        default: break;
    }

    ctx->pc = 0x186f68u;

    // 0x186f68: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x186f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x186f6c: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x186f6cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x186f70: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x186f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x186f74: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x186f74u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186f78: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x186f78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x186f7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x186f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x186f80: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x186f80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x186f84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x186f84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x186f88: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x186f88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x186f8c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x186f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x186f90: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x186f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x186f94: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x186f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x186f98: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x186f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x186f9c: 0x3c150028  lui         $s5, 0x28
    ctx->pc = 0x186f9cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)40 << 16));
    // 0x186fa0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x186fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x186fa4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x186fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x186fa8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x186fa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x186fac: 0x2421fa18  addiu       $at, $at, -0x5E8
    ctx->pc = 0x186facu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294965784));
    // 0x186fb0: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x186fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x186fb4: 0x12a240  sll         $s4, $s2, 9
    ctx->pc = 0x186fb4u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 18), 9));
    // 0x186fb8: 0x8c470034  lw          $a3, 0x34($v0)
    ctx->pc = 0x186fb8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x186fbc: 0x2921821  addu        $v1, $s4, $s2
    ctx->pc = 0x186fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x186fc0: 0x9444002a  lhu         $a0, 0x2A($v0)
    ctx->pc = 0x186fc0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 42)));
    // 0x186fc4: 0x34900  sll         $t1, $v1, 4
    ctx->pc = 0x186fc4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x186fc8: 0xc78821  addu        $s1, $a2, $a3
    ctx->pc = 0x186fc8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x186fcc: 0x9443002c  lhu         $v1, 0x2C($v0)
    ctx->pc = 0x186fccu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x186fd0: 0x2242018  mult        $a0, $s1, $a0
    ctx->pc = 0x186fd0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x186fd4: 0x26aa7080  addiu       $t2, $s5, 0x7080
    ctx->pc = 0x186fd4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 21), 28800));
    // 0x186fd8: 0x12a5821  addu        $t3, $t1, $t2
    ctx->pc = 0x186fd8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 10)));
    // 0x186fdc: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x186FDCu;
    {
        const bool branch_taken_0x186fdc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x186fdc) {
            ctx->pc = 0x186FE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186FDCu;
            // 0x186fe0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x186FE4u;
            goto label_186fe4;
        }
    }
    ctx->pc = 0x186FE4u;
label_186fe4:
    // 0x186fe4: 0x8d620000  lw          $v0, 0x0($t3)
    ctx->pc = 0x186fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x186fe8: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x186fe8u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x186fec: 0x9812  mflo        $s3
    ctx->pc = 0x186fecu;
    SET_GPR_U64(ctx, 19, ctx->lo);
    // 0x186ff0: 0x1448003d  bne         $v0, $t0, . + 4 + (0x3D << 2)
    ctx->pc = 0x186FF0u;
    {
        const bool branch_taken_0x186ff0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 8));
        ctx->pc = 0x186FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186FF0u;
            // 0x186ff4: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186ff0) {
            ctx->pc = 0x1870E8u;
            goto label_1870e8;
        }
    }
    ctx->pc = 0x186FF8u;
    // 0x186ff8: 0x25420010  addiu       $v0, $t2, 0x10
    ctx->pc = 0x186ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), 16));
    // 0x186ffc: 0x1492021  addu        $a0, $t2, $t1
    ctx->pc = 0x186ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x187000: 0x1223821  addu        $a3, $t1, $v0
    ctx->pc = 0x187000u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x187004: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x187004u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187008: 0x2071025  or          $v0, $s0, $a3
    ctx->pc = 0x187008u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 7));
    // 0x18700c: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x18700cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187010: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x187010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x187014: 0xad710000  sw          $s1, 0x0($t3)
    ctx->pc = 0x187014u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 17));
    // 0x187018: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x187018u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18701c: 0xac910004  sw          $s1, 0x4($a0)
    ctx->pc = 0x18701cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 17));
    // 0x187020: 0xacb30008  sw          $s3, 0x8($a1)
    ctx->pc = 0x187020u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 19));
    // 0x187024: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x187024u;
    {
        const bool branch_taken_0x187024 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187024u;
            // 0x187028: 0xac60000c  sw          $zero, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187024) {
            ctx->pc = 0x187090u;
            goto label_187090;
        }
    }
    ctx->pc = 0x18702Cu;
    // 0x18702c: 0x26020400  addiu       $v0, $s0, 0x400
    ctx->pc = 0x18702cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1024));
label_187030:
    // 0x187030: 0x68c30007  ldl         $v1, 0x7($a2)
    ctx->pc = 0x187030u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x187034: 0x6cc30000  ldr         $v1, 0x0($a2)
    ctx->pc = 0x187034u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x187038: 0x68c4000f  ldl         $a0, 0xF($a2)
    ctx->pc = 0x187038u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x18703c: 0x6cc40008  ldr         $a0, 0x8($a2)
    ctx->pc = 0x18703cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x187040: 0x68c50017  ldl         $a1, 0x17($a2)
    ctx->pc = 0x187040u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x187044: 0x6cc50010  ldr         $a1, 0x10($a2)
    ctx->pc = 0x187044u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x187048: 0x68c8001f  ldl         $t0, 0x1F($a2)
    ctx->pc = 0x187048u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x18704c: 0x6cc80018  ldr         $t0, 0x18($a2)
    ctx->pc = 0x18704cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x187050: 0xb0e30007  sdl         $v1, 0x7($a3)
    ctx->pc = 0x187050u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187054: 0xb4e30000  sdr         $v1, 0x0($a3)
    ctx->pc = 0x187054u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187058: 0xb0e4000f  sdl         $a0, 0xF($a3)
    ctx->pc = 0x187058u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18705c: 0xb4e40008  sdr         $a0, 0x8($a3)
    ctx->pc = 0x18705cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187060: 0xb0e50017  sdl         $a1, 0x17($a3)
    ctx->pc = 0x187060u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187064: 0xb4e50010  sdr         $a1, 0x10($a3)
    ctx->pc = 0x187064u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187068: 0xb0e8001f  sdl         $t0, 0x1F($a3)
    ctx->pc = 0x187068u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18706c: 0xb4e80018  sdr         $t0, 0x18($a3)
    ctx->pc = 0x18706cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187070: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x187070u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x187074: 0x0  nop
    ctx->pc = 0x187074u;
    // NOP
    // 0x187078: 0x0  nop
    ctx->pc = 0x187078u;
    // NOP
    // 0x18707c: 0x14c2ffec  bne         $a2, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x18707Cu;
    {
        const bool branch_taken_0x18707c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x187080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18707Cu;
            // 0x187080: 0x24e70020  addiu       $a3, $a3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18707c) {
            ctx->pc = 0x187030u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187030;
        }
    }
    ctx->pc = 0x187084u;
    // 0x187084: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x187084u;
    {
        const bool branch_taken_0x187084 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187084u;
            // 0x187088: 0x2922021  addu        $a0, $s4, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187084) {
            ctx->pc = 0x1870CCu;
            goto label_1870cc;
        }
    }
    ctx->pc = 0x18708Cu;
    // 0x18708c: 0x0  nop
    ctx->pc = 0x18708cu;
    // NOP
label_187090:
    // 0x187090: 0x26020400  addiu       $v0, $s0, 0x400
    ctx->pc = 0x187090u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1024));
label_187094:
    // 0x187094: 0xdcc30000  ld          $v1, 0x0($a2)
    ctx->pc = 0x187094u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x187098: 0xdcc40008  ld          $a0, 0x8($a2)
    ctx->pc = 0x187098u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x18709c: 0xdcc50010  ld          $a1, 0x10($a2)
    ctx->pc = 0x18709cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x1870a0: 0xdcc80018  ld          $t0, 0x18($a2)
    ctx->pc = 0x1870a0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x1870a4: 0xfce30000  sd          $v1, 0x0($a3)
    ctx->pc = 0x1870a4u;
    WRITE64(ADD32(GPR_U32(ctx, 7), 0), GPR_U64(ctx, 3));
    // 0x1870a8: 0xfce40008  sd          $a0, 0x8($a3)
    ctx->pc = 0x1870a8u;
    WRITE64(ADD32(GPR_U32(ctx, 7), 8), GPR_U64(ctx, 4));
    // 0x1870ac: 0xfce50010  sd          $a1, 0x10($a3)
    ctx->pc = 0x1870acu;
    WRITE64(ADD32(GPR_U32(ctx, 7), 16), GPR_U64(ctx, 5));
    // 0x1870b0: 0xfce80018  sd          $t0, 0x18($a3)
    ctx->pc = 0x1870b0u;
    WRITE64(ADD32(GPR_U32(ctx, 7), 24), GPR_U64(ctx, 8));
    // 0x1870b4: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x1870b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x1870b8: 0x0  nop
    ctx->pc = 0x1870b8u;
    // NOP
    // 0x1870bc: 0x0  nop
    ctx->pc = 0x1870bcu;
    // NOP
    // 0x1870c0: 0x14c2fff4  bne         $a2, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1870C0u;
    {
        const bool branch_taken_0x1870c0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x1870C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1870C0u;
            // 0x1870c4: 0x24e70020  addiu       $a3, $a3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1870c0) {
            ctx->pc = 0x187094u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187094;
        }
    }
    ctx->pc = 0x1870C8u;
    // 0x1870c8: 0x2922021  addu        $a0, $s4, $s2
    ctx->pc = 0x1870c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
label_1870cc:
    // 0x1870cc: 0x26a27080  addiu       $v0, $s5, 0x7080
    ctx->pc = 0x1870ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 28800));
    // 0x1870d0: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1870d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1870d4: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1870d4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1870d8: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1870d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1870dc: 0x10000088  b           . + 4 + (0x88 << 2)
    ctx->pc = 0x1870DCu;
    {
        const bool branch_taken_0x1870dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1870E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1870DCu;
            // 0x1870e0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1870dc) {
            ctx->pc = 0x187300u;
            goto label_187300;
        }
    }
    ctx->pc = 0x1870E4u;
    // 0x1870e4: 0x0  nop
    ctx->pc = 0x1870e4u;
    // NOP
label_1870e8:
    // 0x1870e8: 0x25430004  addiu       $v1, $t2, 0x4
    ctx->pc = 0x1870e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
    // 0x1870ec: 0x1232021  addu        $a0, $t1, $v1
    ctx->pc = 0x1870ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x1870f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1870f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1870f4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1870f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1870f8: 0x16220041  bne         $s1, $v0, . + 4 + (0x41 << 2)
    ctx->pc = 0x1870F8u;
    {
        const bool branch_taken_0x1870f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x1870FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1870F8u;
            // 0x1870fc: 0x2543000c  addiu       $v1, $t2, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1870f8) {
            ctx->pc = 0x187200u;
            goto label_187200;
        }
    }
    ctx->pc = 0x187100u;
    // 0x187100: 0x1233821  addu        $a3, $t1, $v1
    ctx->pc = 0x187100u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x187104: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x187104u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x187108: 0x28420008  slti        $v0, $v0, 0x8
    ctx->pc = 0x187108u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x18710c: 0x1040003c  beqz        $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x18710Cu;
    {
        const bool branch_taken_0x18710c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18710Cu;
            // 0x187110: 0x1491021  addu        $v0, $t2, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18710c) {
            ctx->pc = 0x187200u;
            goto label_187200;
        }
    }
    ctx->pc = 0x187114u;
    // 0x187114: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x187114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x187118: 0x14730039  bne         $v1, $s3, . + 4 + (0x39 << 2)
    ctx->pc = 0x187118u;
    {
        const bool branch_taken_0x187118 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        ctx->pc = 0x18711Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187118u;
            // 0x18711c: 0x25420010  addiu       $v0, $t2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187118) {
            ctx->pc = 0x187200u;
            goto label_187200;
        }
    }
    ctx->pc = 0x187120u;
    // 0x187120: 0xac910000  sw          $s1, 0x0($a0)
    ctx->pc = 0x187120u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17));
    // 0x187124: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x187124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x187128: 0x31a80  sll         $v1, $v1, 10
    ctx->pc = 0x187128u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
    // 0x18712c: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x18712cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x187130: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x187130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187134: 0x2022025  or          $a0, $s0, $v0
    ctx->pc = 0x187134u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x187138: 0x30840007  andi        $a0, $a0, 0x7
    ctx->pc = 0x187138u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)7);
    // 0x18713c: 0x1080001a  beqz        $a0, . + 4 + (0x1A << 2)
    ctx->pc = 0x18713Cu;
    {
        const bool branch_taken_0x18713c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x187140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18713Cu;
            // 0x187140: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18713c) {
            ctx->pc = 0x1871A8u;
            goto label_1871a8;
        }
    }
    ctx->pc = 0x187144u;
    // 0x187144: 0x26040400  addiu       $a0, $s0, 0x400
    ctx->pc = 0x187144u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1024));
label_187148:
    // 0x187148: 0x68c30007  ldl         $v1, 0x7($a2)
    ctx->pc = 0x187148u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x18714c: 0x6cc30000  ldr         $v1, 0x0($a2)
    ctx->pc = 0x18714cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x187150: 0x68c5000f  ldl         $a1, 0xF($a2)
    ctx->pc = 0x187150u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x187154: 0x6cc50008  ldr         $a1, 0x8($a2)
    ctx->pc = 0x187154u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x187158: 0x68c70017  ldl         $a3, 0x17($a2)
    ctx->pc = 0x187158u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x18715c: 0x6cc70010  ldr         $a3, 0x10($a2)
    ctx->pc = 0x18715cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x187160: 0x68c8001f  ldl         $t0, 0x1F($a2)
    ctx->pc = 0x187160u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x187164: 0x6cc80018  ldr         $t0, 0x18($a2)
    ctx->pc = 0x187164u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x187168: 0xb0430007  sdl         $v1, 0x7($v0)
    ctx->pc = 0x187168u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18716c: 0xb4430000  sdr         $v1, 0x0($v0)
    ctx->pc = 0x18716cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187170: 0xb045000f  sdl         $a1, 0xF($v0)
    ctx->pc = 0x187170u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187174: 0xb4450008  sdr         $a1, 0x8($v0)
    ctx->pc = 0x187174u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187178: 0xb0470017  sdl         $a3, 0x17($v0)
    ctx->pc = 0x187178u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18717c: 0xb4470010  sdr         $a3, 0x10($v0)
    ctx->pc = 0x18717cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187180: 0xb048001f  sdl         $t0, 0x1F($v0)
    ctx->pc = 0x187180u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187184: 0xb4480018  sdr         $t0, 0x18($v0)
    ctx->pc = 0x187184u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187188: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x187188u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x18718c: 0x0  nop
    ctx->pc = 0x18718cu;
    // NOP
    // 0x187190: 0x0  nop
    ctx->pc = 0x187190u;
    // NOP
    // 0x187194: 0x14c4ffec  bne         $a2, $a0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x187194u;
    {
        const bool branch_taken_0x187194 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        ctx->pc = 0x187198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187194u;
            // 0x187198: 0x24420020  addiu       $v0, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187194) {
            ctx->pc = 0x187148u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187148;
        }
    }
    ctx->pc = 0x18719Cu;
    // 0x18719c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18719Cu;
    {
        const bool branch_taken_0x18719c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1871A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18719Cu;
            // 0x1871a0: 0x2922021  addu        $a0, $s4, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18719c) {
            ctx->pc = 0x1871E4u;
            goto label_1871e4;
        }
    }
    ctx->pc = 0x1871A4u;
    // 0x1871a4: 0x0  nop
    ctx->pc = 0x1871a4u;
    // NOP
label_1871a8:
    // 0x1871a8: 0x26040400  addiu       $a0, $s0, 0x400
    ctx->pc = 0x1871a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1024));
label_1871ac:
    // 0x1871ac: 0xdcc30000  ld          $v1, 0x0($a2)
    ctx->pc = 0x1871acu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1871b0: 0xdcc50008  ld          $a1, 0x8($a2)
    ctx->pc = 0x1871b0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1871b4: 0xdcc70010  ld          $a3, 0x10($a2)
    ctx->pc = 0x1871b4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x1871b8: 0xdcc80018  ld          $t0, 0x18($a2)
    ctx->pc = 0x1871b8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x1871bc: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x1871bcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x1871c0: 0xfc450008  sd          $a1, 0x8($v0)
    ctx->pc = 0x1871c0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 5));
    // 0x1871c4: 0xfc470010  sd          $a3, 0x10($v0)
    ctx->pc = 0x1871c4u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 7));
    // 0x1871c8: 0xfc480018  sd          $t0, 0x18($v0)
    ctx->pc = 0x1871c8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 8));
    // 0x1871cc: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x1871ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x1871d0: 0x0  nop
    ctx->pc = 0x1871d0u;
    // NOP
    // 0x1871d4: 0x0  nop
    ctx->pc = 0x1871d4u;
    // NOP
    // 0x1871d8: 0x14c4fff4  bne         $a2, $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1871D8u;
    {
        const bool branch_taken_0x1871d8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        ctx->pc = 0x1871DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1871D8u;
            // 0x1871dc: 0x24420020  addiu       $v0, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1871d8) {
            ctx->pc = 0x1871ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1871ac;
        }
    }
    ctx->pc = 0x1871E0u;
    // 0x1871e0: 0x2922021  addu        $a0, $s4, $s2
    ctx->pc = 0x1871e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
label_1871e4:
    // 0x1871e4: 0x26a27080  addiu       $v0, $s5, 0x7080
    ctx->pc = 0x1871e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 28800));
    // 0x1871e8: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1871e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1871ec: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1871ecu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1871f0: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1871f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1871f4: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x1871F4u;
    {
        const bool branch_taken_0x1871f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1871F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1871F4u;
            // 0x1871f8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1871f4) {
            ctx->pc = 0x187300u;
            goto label_187300;
        }
    }
    ctx->pc = 0x1871FCu;
    // 0x1871fc: 0x0  nop
    ctx->pc = 0x1871fcu;
    // NOP
label_187200:
    // 0x187200: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x187200u;
    SET_GPR_U32(ctx, 31, 0x187208u);
    ctx->pc = 0x187204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187200u;
            // 0x187204: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187208u; }
        if (ctx->pc != 0x187208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187208u; }
        if (ctx->pc != 0x187208u) { return; }
    }
    ctx->pc = 0x187208u;
label_187208:
    // 0x187208: 0x26a37080  addiu       $v1, $s5, 0x7080
    ctx->pc = 0x187208u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 28800));
    // 0x18720c: 0x40502d  daddu       $t2, $v0, $zero
    ctx->pc = 0x18720cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187210: 0x2921021  addu        $v0, $s4, $s2
    ctx->pc = 0x187210u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x187214: 0x24640010  addiu       $a0, $v1, 0x10
    ctx->pc = 0x187214u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x187218: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x187218u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x18721c: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x18721cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187220: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x187220u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187224: 0x444821  addu        $t1, $v0, $a0
    ctx->pc = 0x187224u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x187228: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x187228u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18722c: 0x1092025  or          $a0, $t0, $t1
    ctx->pc = 0x18722cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) | GPR_U64(ctx, 9));
    // 0x187230: 0x433821  addu        $a3, $v0, $v1
    ctx->pc = 0x187230u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x187234: 0x30840007  andi        $a0, $a0, 0x7
    ctx->pc = 0x187234u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)7);
    // 0x187238: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x187238u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18723c: 0xacf10000  sw          $s1, 0x0($a3)
    ctx->pc = 0x18723cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 17));
    // 0x187240: 0xacb10004  sw          $s1, 0x4($a1)
    ctx->pc = 0x187240u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 17));
    // 0x187244: 0xacd30008  sw          $s3, 0x8($a2)
    ctx->pc = 0x187244u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 19));
    // 0x187248: 0x10800019  beqz        $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x187248u;
    {
        const bool branch_taken_0x187248 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x18724Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187248u;
            // 0x18724c: 0xac60000c  sw          $zero, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187248) {
            ctx->pc = 0x1872B0u;
            goto label_1872b0;
        }
    }
    ctx->pc = 0x187250u;
    // 0x187250: 0x25020400  addiu       $v0, $t0, 0x400
    ctx->pc = 0x187250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1024));
label_187254:
    // 0x187254: 0x69030007  ldl         $v1, 0x7($t0)
    ctx->pc = 0x187254u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x187258: 0x6d030000  ldr         $v1, 0x0($t0)
    ctx->pc = 0x187258u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x18725c: 0x6904000f  ldl         $a0, 0xF($t0)
    ctx->pc = 0x18725cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x187260: 0x6d040008  ldr         $a0, 0x8($t0)
    ctx->pc = 0x187260u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x187264: 0x69050017  ldl         $a1, 0x17($t0)
    ctx->pc = 0x187264u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x187268: 0x6d050010  ldr         $a1, 0x10($t0)
    ctx->pc = 0x187268u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x18726c: 0x6906001f  ldl         $a2, 0x1F($t0)
    ctx->pc = 0x18726cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x187270: 0x6d060018  ldr         $a2, 0x18($t0)
    ctx->pc = 0x187270u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x187274: 0xb1230007  sdl         $v1, 0x7($t1)
    ctx->pc = 0x187274u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187278: 0xb5230000  sdr         $v1, 0x0($t1)
    ctx->pc = 0x187278u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18727c: 0xb124000f  sdl         $a0, 0xF($t1)
    ctx->pc = 0x18727cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187280: 0xb5240008  sdr         $a0, 0x8($t1)
    ctx->pc = 0x187280u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187284: 0xb1250017  sdl         $a1, 0x17($t1)
    ctx->pc = 0x187284u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187288: 0xb5250010  sdr         $a1, 0x10($t1)
    ctx->pc = 0x187288u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18728c: 0xb126001f  sdl         $a2, 0x1F($t1)
    ctx->pc = 0x18728cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187290: 0xb5260018  sdr         $a2, 0x18($t1)
    ctx->pc = 0x187290u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187294: 0x25080020  addiu       $t0, $t0, 0x20
    ctx->pc = 0x187294u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 32));
    // 0x187298: 0x0  nop
    ctx->pc = 0x187298u;
    // NOP
    // 0x18729c: 0x0  nop
    ctx->pc = 0x18729cu;
    // NOP
    // 0x1872a0: 0x1502ffec  bne         $t0, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1872A0u;
    {
        const bool branch_taken_0x1872a0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x1872A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1872A0u;
            // 0x1872a4: 0x25290020  addiu       $t1, $t1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1872a0) {
            ctx->pc = 0x187254u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187254;
        }
    }
    ctx->pc = 0x1872A8u;
    // 0x1872a8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1872A8u;
    {
        const bool branch_taken_0x1872a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1872ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1872A8u;
            // 0x1872ac: 0x2922021  addu        $a0, $s4, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1872a8) {
            ctx->pc = 0x1872ECu;
            goto label_1872ec;
        }
    }
    ctx->pc = 0x1872B0u;
label_1872b0:
    // 0x1872b0: 0x25020400  addiu       $v0, $t0, 0x400
    ctx->pc = 0x1872b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1024));
label_1872b4:
    // 0x1872b4: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x1872b4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1872b8: 0xdd030008  ld          $v1, 0x8($t0)
    ctx->pc = 0x1872b8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x1872bc: 0xdd040010  ld          $a0, 0x10($t0)
    ctx->pc = 0x1872bcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x1872c0: 0xdd050018  ld          $a1, 0x18($t0)
    ctx->pc = 0x1872c0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 8), 24)));
    // 0x1872c4: 0xfd270000  sd          $a3, 0x0($t1)
    ctx->pc = 0x1872c4u;
    WRITE64(ADD32(GPR_U32(ctx, 9), 0), GPR_U64(ctx, 7));
    // 0x1872c8: 0xfd230008  sd          $v1, 0x8($t1)
    ctx->pc = 0x1872c8u;
    WRITE64(ADD32(GPR_U32(ctx, 9), 8), GPR_U64(ctx, 3));
    // 0x1872cc: 0xfd240010  sd          $a0, 0x10($t1)
    ctx->pc = 0x1872ccu;
    WRITE64(ADD32(GPR_U32(ctx, 9), 16), GPR_U64(ctx, 4));
    // 0x1872d0: 0xfd250018  sd          $a1, 0x18($t1)
    ctx->pc = 0x1872d0u;
    WRITE64(ADD32(GPR_U32(ctx, 9), 24), GPR_U64(ctx, 5));
    // 0x1872d4: 0x25080020  addiu       $t0, $t0, 0x20
    ctx->pc = 0x1872d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 32));
    // 0x1872d8: 0x0  nop
    ctx->pc = 0x1872d8u;
    // NOP
    // 0x1872dc: 0x0  nop
    ctx->pc = 0x1872dcu;
    // NOP
    // 0x1872e0: 0x1502fff4  bne         $t0, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1872E0u;
    {
        const bool branch_taken_0x1872e0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x1872E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1872E0u;
            // 0x1872e4: 0x25290020  addiu       $t1, $t1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1872e0) {
            ctx->pc = 0x1872B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1872b4;
        }
    }
    ctx->pc = 0x1872E8u;
    // 0x1872e8: 0x2922021  addu        $a0, $s4, $s2
    ctx->pc = 0x1872e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
label_1872ec:
    // 0x1872ec: 0x26a27080  addiu       $v0, $s5, 0x7080
    ctx->pc = 0x1872ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 28800));
    // 0x1872f0: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1872f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1872f4: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1872f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1872f8: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1872f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1872fc: 0x140102d  daddu       $v0, $t2, $zero
    ctx->pc = 0x1872fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_187300:
    // 0x187300: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x187300u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x187304: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x187304u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x187308: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x187308u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x18730c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18730cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x187310: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x187310u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x187314: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x187314u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187318: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x187318u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x18731c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x18731cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x187320: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x187320u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x187324: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x187324u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x187328: 0x3e00008  jr          $ra
    ctx->pc = 0x187328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18732Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187328u;
            // 0x18732c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x186FE4u: goto label_186fe4;
            case 0x187030u: goto label_187030;
            case 0x187090u: goto label_187090;
            case 0x187094u: goto label_187094;
            case 0x1870CCu: goto label_1870cc;
            case 0x1870E8u: goto label_1870e8;
            case 0x187148u: goto label_187148;
            case 0x1871A8u: goto label_1871a8;
            case 0x1871ACu: goto label_1871ac;
            case 0x1871E4u: goto label_1871e4;
            case 0x187200u: goto label_187200;
            case 0x187208u: goto label_187208;
            case 0x187254u: goto label_187254;
            case 0x1872B0u: goto label_1872b0;
            case 0x1872B4u: goto label_1872b4;
            case 0x1872ECu: goto label_1872ec;
            case 0x187300u: goto label_187300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187330u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

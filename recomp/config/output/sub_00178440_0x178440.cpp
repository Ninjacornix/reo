#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178440
// Address: 0x178440 - 0x17859c
void sub_00178440_0x178440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178440_0x178440");
#endif

    switch (ctx->pc) {
        case 0x178468u: goto label_178468;
        case 0x1784ccu: goto label_1784cc;
        case 0x178558u: goto label_178558;
        case 0x17856cu: goto label_17856c;
        case 0x178574u: goto label_178574;
        default: break;
    }

    ctx->pc = 0x178440u;

    // 0x178440: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x178440u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x178444: 0x27bdfec0  addiu       $sp, $sp, -0x140
    ctx->pc = 0x178444u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x178448: 0x24630b60  addiu       $v1, $v1, 0xB60
    ctx->pc = 0x178448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2912));
    // 0x17844c: 0xffb00120  sd          $s0, 0x120($sp)
    ctx->pc = 0x17844cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 16));
    // 0x178450: 0x30620007  andi        $v0, $v1, 0x7
    ctx->pc = 0x178450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x178454: 0xffb10128  sd          $s1, 0x128($sp)
    ctx->pc = 0x178454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 296), GPR_U64(ctx, 17));
    // 0x178458: 0xffbf0130  sd          $ra, 0x130($sp)
    ctx->pc = 0x178458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 31));
    // 0x17845c: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x17845Cu;
    {
        const bool branch_taken_0x17845c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17845Cu;
            // 0x178460: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17845c) {
            ctx->pc = 0x1784C8u;
            goto label_1784c8;
        }
    }
    ctx->pc = 0x178464u;
    // 0x178464: 0x24620100  addiu       $v0, $v1, 0x100
    ctx->pc = 0x178464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 256));
label_178468:
    // 0x178468: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x178468u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x17846c: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x17846cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x178470: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x178470u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x178474: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x178474u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x178478: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x178478u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x17847c: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x17847cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x178480: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x178480u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x178484: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x178484u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x178488: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x178488u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17848c: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x17848cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178490: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x178490u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178494: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x178494u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178498: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x178498u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17849c: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x17849cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1784a0: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x1784a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1784a4: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x1784a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1784a8: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1784a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1784ac: 0x0  nop
    ctx->pc = 0x1784acu;
    // NOP
    // 0x1784b0: 0x0  nop
    ctx->pc = 0x1784b0u;
    // NOP
    // 0x1784b4: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1784B4u;
    {
        const bool branch_taken_0x1784b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1784B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1784B4u;
            // 0x1784b8: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1784b4) {
            ctx->pc = 0x178468u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_178468;
        }
    }
    ctx->pc = 0x1784BCu;
    // 0x1784bc: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1784BCu;
    {
        const bool branch_taken_0x1784bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1784bc) {
            ctx->pc = 0x178500u;
            goto label_178500;
        }
    }
    ctx->pc = 0x1784C4u;
    // 0x1784c4: 0x0  nop
    ctx->pc = 0x1784c4u;
    // NOP
label_1784c8:
    // 0x1784c8: 0x24620100  addiu       $v0, $v1, 0x100
    ctx->pc = 0x1784c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 256));
label_1784cc:
    // 0x1784cc: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x1784ccu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1784d0: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x1784d0u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1784d4: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x1784d4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1784d8: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x1784d8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1784dc: 0xfc850000  sd          $a1, 0x0($a0)
    ctx->pc = 0x1784dcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x1784e0: 0xfc860008  sd          $a2, 0x8($a0)
    ctx->pc = 0x1784e0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x1784e4: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x1784e4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x1784e8: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x1784e8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x1784ec: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1784ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1784f0: 0x0  nop
    ctx->pc = 0x1784f0u;
    // NOP
    // 0x1784f4: 0x0  nop
    ctx->pc = 0x1784f4u;
    // NOP
    // 0x1784f8: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1784F8u;
    {
        const bool branch_taken_0x1784f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1784FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1784F8u;
            // 0x1784fc: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1784f8) {
            ctx->pc = 0x1784CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1784cc;
        }
    }
    ctx->pc = 0x178500u;
label_178500:
    // 0x178500: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x178500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x178504: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x178504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x178508: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x178508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x17850c: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x17850cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x178510: 0x80670010  lb          $a3, 0x10($v1)
    ctx->pc = 0x178510u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x178514: 0x80680011  lb          $t0, 0x11($v1)
    ctx->pc = 0x178514u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 17)));
    // 0x178518: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x178518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17851c: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x17851cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178520: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x178520u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178524: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x178524u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178528: 0xa0870010  sb          $a3, 0x10($a0)
    ctx->pc = 0x178528u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 16), (uint8_t)GPR_U32(ctx, 7));
    // 0x17852c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17852cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x178530: 0x2451f1dc  addiu       $s1, $v0, -0xE24
    ctx->pc = 0x178530u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963676));
    // 0x178534: 0xa0880011  sb          $t0, 0x11($a0)
    ctx->pc = 0x178534u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 17), (uint8_t)GPR_U32(ctx, 8));
    // 0x178538: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x178538u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17853c: 0x10800012  beqz        $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17853Cu;
    {
        const bool branch_taken_0x17853c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x178540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17853Cu;
            // 0x178540: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17853c) {
            ctx->pc = 0x178588u;
            goto label_178588;
        }
    }
    ctx->pc = 0x178544u;
    // 0x178544: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x178544u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178548: 0x8c46f1d8  lw          $a2, -0xE28($v0)
    ctx->pc = 0x178548u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963672)));
    // 0x17854c: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x17854cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x178550: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x178550u;
    SET_GPR_U32(ctx, 31, 0x178558u);
    ctx->pc = 0x178554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178550u;
            // 0x178554: 0x2610f1e4  addiu       $s0, $s0, -0xE1C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963684));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178558u; }
        if (ctx->pc != 0x178558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178558u; }
        if (ctx->pc != 0x178558u) { return; }
    }
    ctx->pc = 0x178558u;
label_178558:
    // 0x178558: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x178558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17855c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17855cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178560: 0x0  nop
    ctx->pc = 0x178560u;
    // NOP
    // 0x178564: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x178564u;
    SET_GPR_U32(ctx, 31, 0x17856Cu);
    ctx->pc = 0x178568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178564u;
            // 0x178568: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17856Cu; }
        if (ctx->pc != 0x17856Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17856Cu; }
        if (ctx->pc != 0x17856Cu) { return; }
    }
    ctx->pc = 0x17856Cu;
label_17856c:
    // 0x17856c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x17856Cu;
    SET_GPR_U32(ctx, 31, 0x178574u);
    ctx->pc = 0x178570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17856Cu;
            // 0x178570: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178574u; }
        if (ctx->pc != 0x178574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178574u; }
        if (ctx->pc != 0x178574u) { return; }
    }
    ctx->pc = 0x178574u;
label_178574:
    // 0x178574: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x178574u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x178578: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x178578u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x17857c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17857cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x178580: 0xac83f1e8  sw          $v1, -0xE18($a0)
    ctx->pc = 0x178580u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294963688), GPR_U32(ctx, 3));
    // 0x178584: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x178584u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
label_178588:
    // 0x178588: 0xdfb00120  ld          $s0, 0x120($sp)
    ctx->pc = 0x178588u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x17858c: 0xdfb10128  ld          $s1, 0x128($sp)
    ctx->pc = 0x17858cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 296)));
    // 0x178590: 0xdfbf0130  ld          $ra, 0x130($sp)
    ctx->pc = 0x178590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x178594: 0x3e00008  jr          $ra
    ctx->pc = 0x178594u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178594u;
            // 0x178598: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178558u: goto label_178558;
            case 0x17856Cu: goto label_17856c;
            case 0x178574u: goto label_178574;
            case 0x178588u: goto label_178588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17859Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

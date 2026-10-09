#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001783D8
// Address: 0x1783d8 - 0x178910
void sub_001783D8_0x1783d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001783D8_0x1783d8");
#endif

    switch (ctx->pc) {
        case 0x1783f0u: goto label_1783f0;
        case 0x178468u: goto label_178468;
        case 0x1784ccu: goto label_1784cc;
        case 0x178558u: goto label_178558;
        case 0x17856cu: goto label_17856c;
        case 0x178574u: goto label_178574;
        case 0x1785fcu: goto label_1785fc;
        case 0x178610u: goto label_178610;
        case 0x17861cu: goto label_17861c;
        case 0x178628u: goto label_178628;
        case 0x178638u: goto label_178638;
        case 0x178648u: goto label_178648;
        case 0x178654u: goto label_178654;
        case 0x178660u: goto label_178660;
        case 0x17866cu: goto label_17866c;
        case 0x178760u: goto label_178760;
        case 0x178778u: goto label_178778;
        case 0x178828u: goto label_178828;
        case 0x1788ccu: goto label_1788cc;
        case 0x1788e0u: goto label_1788e0;
        default: break;
    }

    ctx->pc = 0x1783d8u;

    // 0x1783d8: 0x8c850010  lw          $a1, 0x10($a0)
    ctx->pc = 0x1783d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1783dc: 0x18a0000b  blez        $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x1783DCu;
    {
        const bool branch_taken_0x1783dc = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x1783E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1783DCu;
            // 0x1783e0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1783dc) {
            ctx->pc = 0x17840Cu;
            goto label_17840c;
        }
    }
    ctx->pc = 0x1783E4u;
    // 0x1783e4: 0x24840018  addiu       $a0, $a0, 0x18
    ctx->pc = 0x1783e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24));
    // 0x1783e8: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1783e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1783ec: 0x0  nop
    ctx->pc = 0x1783ecu;
    // NOP
label_1783f0:
    // 0x1783f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1783f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1783f4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1783f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1783f8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1783f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1783fc: 0x0  nop
    ctx->pc = 0x1783fcu;
    // NOP
    // 0x178400: 0x0  nop
    ctx->pc = 0x178400u;
    // NOP
    // 0x178404: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x178404u;
    {
        const bool branch_taken_0x178404 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x178408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178404u;
            // 0x178408: 0xc23021  addu        $a2, $a2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178404) {
            ctx->pc = 0x1783F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1783f0;
        }
    }
    ctx->pc = 0x17840Cu;
label_17840c:
    // 0x17840c: 0xc5001a  div         $zero, $a2, $a1
    ctx->pc = 0x17840cu;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x178410: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x178410u;
    {
        const bool branch_taken_0x178410 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x178410) {
            ctx->pc = 0x178414u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x178410u;
            // 0x178414: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x178418u;
            goto label_178418;
        }
    }
    ctx->pc = 0x178418u;
label_178418:
    // 0x178418: 0x1012  mflo        $v0
    ctx->pc = 0x178418u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x17841c: 0x3e00008  jr          $ra
    ctx->pc = 0x17841Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1783F0u: goto label_1783f0;
            case 0x17840Cu: goto label_17840c;
            case 0x178418u: goto label_178418;
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178558u: goto label_178558;
            case 0x17856Cu: goto label_17856c;
            case 0x178574u: goto label_178574;
            case 0x178588u: goto label_178588;
            case 0x1785FCu: goto label_1785fc;
            case 0x178610u: goto label_178610;
            case 0x17861Cu: goto label_17861c;
            case 0x178628u: goto label_178628;
            case 0x178638u: goto label_178638;
            case 0x178648u: goto label_178648;
            case 0x178654u: goto label_178654;
            case 0x178660u: goto label_178660;
            case 0x17866Cu: goto label_17866c;
            case 0x178760u: goto label_178760;
            case 0x178778u: goto label_178778;
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178828u: goto label_178828;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            case 0x1788CCu: goto label_1788cc;
            case 0x1788E0u: goto label_1788e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178424u;
    // 0x178424: 0x0  nop
    ctx->pc = 0x178424u;
    // NOP
    // 0x178428: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x178428u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17842c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17842cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x178430: 0xac44f1dc  sw          $a0, -0xE24($v0)
    ctx->pc = 0x178430u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963676), GPR_U32(ctx, 4));
    // 0x178434: 0x3e00008  jr          $ra
    ctx->pc = 0x178434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178434u;
            // 0x178438: 0xac65f1d8  sw          $a1, -0xE28($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294963672), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1783F0u: goto label_1783f0;
            case 0x17840Cu: goto label_17840c;
            case 0x178418u: goto label_178418;
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178558u: goto label_178558;
            case 0x17856Cu: goto label_17856c;
            case 0x178574u: goto label_178574;
            case 0x178588u: goto label_178588;
            case 0x1785FCu: goto label_1785fc;
            case 0x178610u: goto label_178610;
            case 0x17861Cu: goto label_17861c;
            case 0x178628u: goto label_178628;
            case 0x178638u: goto label_178638;
            case 0x178648u: goto label_178648;
            case 0x178654u: goto label_178654;
            case 0x178660u: goto label_178660;
            case 0x17866Cu: goto label_17866c;
            case 0x178760u: goto label_178760;
            case 0x178778u: goto label_178778;
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178828u: goto label_178828;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            case 0x1788CCu: goto label_1788cc;
            case 0x1788E0u: goto label_1788e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17843Cu;
    // 0x17843c: 0x0  nop
    ctx->pc = 0x17843cu;
    // NOP
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
            case 0x1783F0u: goto label_1783f0;
            case 0x17840Cu: goto label_17840c;
            case 0x178418u: goto label_178418;
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178558u: goto label_178558;
            case 0x17856Cu: goto label_17856c;
            case 0x178574u: goto label_178574;
            case 0x178588u: goto label_178588;
            case 0x1785FCu: goto label_1785fc;
            case 0x178610u: goto label_178610;
            case 0x17861Cu: goto label_17861c;
            case 0x178628u: goto label_178628;
            case 0x178638u: goto label_178638;
            case 0x178648u: goto label_178648;
            case 0x178654u: goto label_178654;
            case 0x178660u: goto label_178660;
            case 0x17866Cu: goto label_17866c;
            case 0x178760u: goto label_178760;
            case 0x178778u: goto label_178778;
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178828u: goto label_178828;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            case 0x1788CCu: goto label_1788cc;
            case 0x1788E0u: goto label_1788e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17859Cu;
    // 0x17859c: 0x0  nop
    ctx->pc = 0x17859cu;
    // NOP
    // 0x1785a0: 0x27bdfe00  addiu       $sp, $sp, -0x200
    ctx->pc = 0x1785a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966784));
    // 0x1785a4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1785a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1785a8: 0xffbe01f0  sd          $fp, 0x1F0($sp)
    ctx->pc = 0x1785a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 496), GPR_U64(ctx, 30));
    // 0x1785ac: 0xffb001b0  sd          $s0, 0x1B0($sp)
    ctx->pc = 0x1785acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 432), GPR_U64(ctx, 16));
    // 0x1785b0: 0x2463f1dc  addiu       $v1, $v1, -0xE24
    ctx->pc = 0x1785b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963676));
    // 0x1785b4: 0xffb101b8  sd          $s1, 0x1B8($sp)
    ctx->pc = 0x1785b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 440), GPR_U64(ctx, 17));
    // 0x1785b8: 0xffb201c0  sd          $s2, 0x1C0($sp)
    ctx->pc = 0x1785b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 448), GPR_U64(ctx, 18));
    // 0x1785bc: 0xffb301c8  sd          $s3, 0x1C8($sp)
    ctx->pc = 0x1785bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 456), GPR_U64(ctx, 19));
    // 0x1785c0: 0xffb401d0  sd          $s4, 0x1D0($sp)
    ctx->pc = 0x1785c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 464), GPR_U64(ctx, 20));
    // 0x1785c4: 0xffb501d8  sd          $s5, 0x1D8($sp)
    ctx->pc = 0x1785c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 472), GPR_U64(ctx, 21));
    // 0x1785c8: 0xffb601e0  sd          $s6, 0x1E0($sp)
    ctx->pc = 0x1785c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 480), GPR_U64(ctx, 22));
    // 0x1785cc: 0xffb701e8  sd          $s7, 0x1E8($sp)
    ctx->pc = 0x1785ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 488), GPR_U64(ctx, 23));
    // 0x1785d0: 0xffbf01f8  sd          $ra, 0x1F8($sp)
    ctx->pc = 0x1785d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 504), GPR_U64(ctx, 31));
    // 0x1785d4: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1785d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1785d8: 0x10400077  beqz        $v0, . + 4 + (0x77 << 2)
    ctx->pc = 0x1785D8u;
    {
        const bool branch_taken_0x1785d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1785DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1785D8u;
            // 0x1785dc: 0x80f02d  daddu       $fp, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1785d8) {
            ctx->pc = 0x1787B8u;
            goto label_1787b8;
        }
    }
    ctx->pc = 0x1785E0u;
    // 0x1785e0: 0xdfd20118  ld          $s2, 0x118($fp)
    ctx->pc = 0x1785e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x1785e4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1785e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1785e8: 0xdfd10120  ld          $s1, 0x120($fp)
    ctx->pc = 0x1785e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 30), 288)));
    // 0x1785ec: 0x24540c78  addiu       $s4, $v0, 0xC78
    ctx->pc = 0x1785ecu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 3192));
    // 0x1785f0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1785f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1785f4: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x1785F4u;
    SET_GPR_U32(ctx, 31, 0x1785FCu);
    ctx->pc = 0x1785F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1785F4u;
            // 0x1785f8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1785FCu; }
        if (ctx->pc != 0x1785FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1785FCu; }
        if (ctx->pc != 0x1785FCu) { return; }
    }
    ctx->pc = 0x1785FCu;
label_1785fc:
    // 0x1785fc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1785fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178600: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x178600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x178604: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x178604u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x178608: 0xc0444ca  jal         func_111328
    ctx->pc = 0x178608u;
    SET_GPR_U32(ctx, 31, 0x178610u);
    ctx->pc = 0x17860Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178608u;
            // 0x17860c: 0xafa201a0  sw          $v0, 0x1A0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 416), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178610u; }
        if (ctx->pc != 0x178610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178610u; }
        if (ctx->pc != 0x178610u) { return; }
    }
    ctx->pc = 0x178610u;
label_178610:
    // 0x178610: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x178610u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178614: 0xc0444ca  jal         func_111328
    ctx->pc = 0x178614u;
    SET_GPR_U32(ctx, 31, 0x17861Cu);
    ctx->pc = 0x178618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178614u;
            // 0x178618: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17861Cu; }
        if (ctx->pc != 0x17861Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17861Cu; }
        if (ctx->pc != 0x17861Cu) { return; }
    }
    ctx->pc = 0x17861Cu;
label_17861c:
    // 0x17861c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17861cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178620: 0xc04480e  jal         func_112038
    ctx->pc = 0x178620u;
    SET_GPR_U32(ctx, 31, 0x178628u);
    ctx->pc = 0x178624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178620u;
            // 0x178624: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178628u; }
        if (ctx->pc != 0x178628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178628u; }
        if (ctx->pc != 0x178628u) { return; }
    }
    ctx->pc = 0x178628u;
label_178628:
    // 0x178628: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x178628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x17862c: 0xdc250cf0  ld          $a1, 0xCF0($at)
    ctx->pc = 0x17862cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 3312)));
    // 0x178630: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x178630u;
    SET_GPR_U32(ctx, 31, 0x178638u);
    ctx->pc = 0x178634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178630u;
            // 0x178634: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178638u; }
        if (ctx->pc != 0x178638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178638u; }
        if (ctx->pc != 0x178638u) { return; }
    }
    ctx->pc = 0x178638u;
label_178638:
    // 0x178638: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x178638u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x17863c: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x17863cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x178640: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x178640u;
    SET_GPR_U32(ctx, 31, 0x178648u);
    ctx->pc = 0x178644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178640u;
            // 0x178644: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178648u; }
        if (ctx->pc != 0x178648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178648u; }
        if (ctx->pc != 0x178648u) { return; }
    }
    ctx->pc = 0x178648u;
label_178648:
    // 0x178648: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x178648u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17864c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x17864Cu;
    SET_GPR_U32(ctx, 31, 0x178654u);
    ctx->pc = 0x178650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17864Cu;
            // 0x178650: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178654u; }
        if (ctx->pc != 0x178654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178654u; }
        if (ctx->pc != 0x178654u) { return; }
    }
    ctx->pc = 0x178654u;
label_178654:
    // 0x178654: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x178654u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178658: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x178658u;
    SET_GPR_U32(ctx, 31, 0x178660u);
    ctx->pc = 0x17865Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178658u;
            // 0x17865c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178660u; }
        if (ctx->pc != 0x178660u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178660u; }
        if (ctx->pc != 0x178660u) { return; }
    }
    ctx->pc = 0x178660u;
label_178660:
    // 0x178660: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x178660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178664: 0xc0448a6  jal         func_112298
    ctx->pc = 0x178664u;
    SET_GPR_U32(ctx, 31, 0x17866Cu);
    ctx->pc = 0x178668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178664u;
            // 0x178668: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17866Cu; }
        if (ctx->pc != 0x17866Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17866Cu; }
        if (ctx->pc != 0x17866Cu) { return; }
    }
    ctx->pc = 0x17866Cu;
label_17866c:
    // 0x17866c: 0x2628ffff  addiu       $t0, $s1, -0x1
    ctx->pc = 0x17866cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x178670: 0xdfc30128  ld          $v1, 0x128($fp)
    ctx->pc = 0x178670u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 30), 296)));
    // 0x178674: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x178674u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x178678: 0xdfcd0108  ld          $t5, 0x108($fp)
    ctx->pc = 0x178678u;
    SET_GPR_U64(ctx, 13, READ64(ADD32(GPR_U32(ctx, 30), 264)));
    // 0x17867c: 0x3c0b7fff  lui         $t3, 0x7FFF
    ctx->pc = 0x17867cu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32767 << 16));
    // 0x178680: 0x356bffff  ori         $t3, $t3, 0xFFFF
    ctx->pc = 0x178680u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)65535);
    // 0x178684: 0xdfcc0188  ld          $t4, 0x188($fp)
    ctx->pc = 0x178684u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 30), 392)));
    // 0x178688: 0x222400a  movz        $t0, $s1, $v0
    ctx->pc = 0x178688u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 17));
    // 0x17868c: 0x8fd90128  lw          $t9, 0x128($fp)
    ctx->pc = 0x17868cu;
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 296)));
    // 0x178690: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x178690u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178694: 0x8fd801b0  lw          $t8, 0x1B0($fp)
    ctx->pc = 0x178694u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 432)));
    // 0x178698: 0x12483f  dsra32      $t1, $s2, 0
    ctx->pc = 0x178698u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 18) >> (32 + 0));
    // 0x17869c: 0x8fcf01a0  lw          $t7, 0x1A0($fp)
    ctx->pc = 0x17869cu;
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 416)));
    // 0x1786a0: 0x1a3682f  dsubu       $t5, $t5, $v1
    ctx->pc = 0x1786a0u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) - GPR_U64(ctx, 3));
    // 0x1786a4: 0x8fce0190  lw          $t6, 0x190($fp)
    ctx->pc = 0x1786a4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 400)));
    // 0x1786a8: 0x183602f  dsubu       $t4, $t4, $v1
    ctx->pc = 0x1786a8u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) - GPR_U64(ctx, 3));
    // 0x1786ac: 0x8fd10008  lw          $s1, 0x8($fp)
    ctx->pc = 0x1786acu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1786b0: 0x24b5824  and         $t3, $s2, $t3
    ctx->pc = 0x1786b0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 18) & GPR_U64(ctx, 11));
    // 0x1786b4: 0x8fc30198  lw          $v1, 0x198($fp)
    ctx->pc = 0x1786b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 408)));
    // 0x1786b8: 0xd683c  dsll32      $t5, $t5, 0
    ctx->pc = 0x1786b8u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) << (32 + 0));
    // 0x1786bc: 0xd683f  dsra32      $t5, $t5, 0
    ctx->pc = 0x1786bcu;
    SET_GPR_S64(ctx, 13, GPR_S64(ctx, 13) >> (32 + 0));
    // 0x1786c0: 0x8fd0019c  lw          $s0, 0x19C($fp)
    ctx->pc = 0x1786c0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 412)));
    // 0x1786c4: 0xc603c  dsll32      $t4, $t4, 0
    ctx->pc = 0x1786c4u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << (32 + 0));
    // 0x1786c8: 0xc603f  dsra32      $t4, $t4, 0
    ctx->pc = 0x1786c8u;
    SET_GPR_S64(ctx, 12, GPR_S64(ctx, 12) >> (32 + 0));
    // 0x1786cc: 0x8fc20194  lw          $v0, 0x194($fp)
    ctx->pc = 0x1786ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 404)));
    // 0x1786d0: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1786d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1786d4: 0x8fd60108  lw          $s6, 0x108($fp)
    ctx->pc = 0x1786d4u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 264)));
    // 0x1786d8: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x1786d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1786dc: 0x8fd301ac  lw          $s3, 0x1AC($fp)
    ctx->pc = 0x1786dcu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 428)));
    // 0x1786e0: 0xb583c  dsll32      $t3, $t3, 0
    ctx->pc = 0x1786e0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) << (32 + 0));
    // 0x1786e4: 0xb583f  dsra32      $t3, $t3, 0
    ctx->pc = 0x1786e4u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 11) >> (32 + 0));
    // 0x1786e8: 0x8fd701b4  lw          $s7, 0x1B4($fp)
    ctx->pc = 0x1786e8u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 436)));
    // 0x1786ec: 0x8fd501b8  lw          $s5, 0x1B8($fp)
    ctx->pc = 0x1786ecu;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 440)));
    // 0x1786f0: 0x8fd40004  lw          $s4, 0x4($fp)
    ctx->pc = 0x1786f0u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1786f4: 0x8fd20188  lw          $s2, 0x188($fp)
    ctx->pc = 0x1786f4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 392)));
    // 0x1786f8: 0x8fca0118  lw          $t2, 0x118($fp)
    ctx->pc = 0x1786f8u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x1786fc: 0x8fa701a0  lw          $a3, 0x1A0($sp)
    ctx->pc = 0x1786fcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x178700: 0xafac0020  sw          $t4, 0x20($sp)
    ctx->pc = 0x178700u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 12));
    // 0x178704: 0xafb10050  sw          $s1, 0x50($sp)
    ctx->pc = 0x178704u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 17));
    // 0x178708: 0xafb00058  sw          $s0, 0x58($sp)
    ctx->pc = 0x178708u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
    // 0x17870c: 0xafb20000  sw          $s2, 0x0($sp)
    ctx->pc = 0x17870cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 18));
    // 0x178710: 0xafb60008  sw          $s6, 0x8($sp)
    ctx->pc = 0x178710u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 22));
    // 0x178714: 0xafb90010  sw          $t9, 0x10($sp)
    ctx->pc = 0x178714u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 25));
    // 0x178718: 0xafad0018  sw          $t5, 0x18($sp)
    ctx->pc = 0x178718u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 13));
    // 0x17871c: 0xafb30028  sw          $s3, 0x28($sp)
    ctx->pc = 0x17871cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 19));
    // 0x178720: 0xafb80030  sw          $t8, 0x30($sp)
    ctx->pc = 0x178720u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 24));
    // 0x178724: 0xafb70038  sw          $s7, 0x38($sp)
    ctx->pc = 0x178724u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 23));
    // 0x178728: 0xafb50040  sw          $s5, 0x40($sp)
    ctx->pc = 0x178728u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 21));
    // 0x17872c: 0xafb40048  sw          $s4, 0x48($sp)
    ctx->pc = 0x17872cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 20));
    // 0x178730: 0xafaf0060  sw          $t7, 0x60($sp)
    ctx->pc = 0x178730u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 15));
    // 0x178734: 0xafae0068  sw          $t6, 0x68($sp)
    ctx->pc = 0x178734u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 14));
    // 0x178738: 0xafa20070  sw          $v0, 0x70($sp)
    ctx->pc = 0x178738u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 2));
    // 0x17873c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17873cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x178740: 0xafa30078  sw          $v1, 0x78($sp)
    ctx->pc = 0x178740u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 3));
    // 0x178744: 0x8c4cef68  lw          $t4, -0x1098($v0)
    ctx->pc = 0x178744u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963048)));
    // 0x178748: 0x8fc301a8  lw          $v1, 0x1A8($fp)
    ctx->pc = 0x178748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 424)));
    // 0x17874c: 0x8fc201a4  lw          $v0, 0x1A4($fp)
    ctx->pc = 0x17874cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 420)));
    // 0x178750: 0xafa30088  sw          $v1, 0x88($sp)
    ctx->pc = 0x178750u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 3));
    // 0x178754: 0xafa20080  sw          $v0, 0x80($sp)
    ctx->pc = 0x178754u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 2));
    // 0x178758: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x178758u;
    SET_GPR_U32(ctx, 31, 0x178760u);
    ctx->pc = 0x17875Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178758u;
            // 0x17875c: 0xafac0090  sw          $t4, 0x90($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178760u; }
        if (ctx->pc != 0x178760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178760u; }
        if (ctx->pc != 0x178760u) { return; }
    }
    ctx->pc = 0x178760u;
label_178760:
    // 0x178760: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x178760u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178764: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x178764u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x178768: 0x2451f1e4  addiu       $s1, $v0, -0xE1C
    ctx->pc = 0x178768u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963684));
    // 0x17876c: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x17876cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x178770: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x178770u;
    SET_GPR_U32(ctx, 31, 0x178778u);
    ctx->pc = 0x178774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178770u;
            // 0x178774: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178778u; }
        if (ctx->pc != 0x178778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178778u; }
        if (ctx->pc != 0x178778u) { return; }
    }
    ctx->pc = 0x178778u;
label_178778:
    // 0x178778: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x178778u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17877c: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x17877cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x178780: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x178780u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x178784: 0x24a5f1dc  addiu       $a1, $a1, -0xE24
    ctx->pc = 0x178784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963676));
    // 0x178788: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x178788u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x17878c: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x17878cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x178790: 0x8c85f1d8  lw          $a1, -0xE28($a0)
    ctx->pc = 0x178790u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294963672)));
    // 0x178794: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x178794u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x178798: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x178798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17879c: 0x2442fc00  addiu       $v0, $v0, -0x400
    ctx->pc = 0x17879cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966272));
    // 0x1787a0: 0x62182b  sltu        $v1, $v1, $v0
    ctx->pc = 0x1787a0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1787a4: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1787A4u;
    {
        const bool branch_taken_0x1787a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1787A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1787A4u;
            // 0x1787a8: 0xdfb001b0  ld          $s0, 0x1B0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 432)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1787a4) {
            ctx->pc = 0x1787BCu;
            goto label_1787bc;
        }
    }
    ctx->pc = 0x1787ACu;
    // 0x1787ac: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1787acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1787b0: 0x8c43f1e8  lw          $v1, -0xE18($v0)
    ctx->pc = 0x1787b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963688)));
    // 0x1787b4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1787b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1787b8:
    // 0x1787b8: 0xdfb001b0  ld          $s0, 0x1B0($sp)
    ctx->pc = 0x1787b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 432)));
label_1787bc:
    // 0x1787bc: 0xdfb101b8  ld          $s1, 0x1B8($sp)
    ctx->pc = 0x1787bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 440)));
    // 0x1787c0: 0xdfb201c0  ld          $s2, 0x1C0($sp)
    ctx->pc = 0x1787c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 448)));
    // 0x1787c4: 0xdfb301c8  ld          $s3, 0x1C8($sp)
    ctx->pc = 0x1787c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 456)));
    // 0x1787c8: 0xdfb401d0  ld          $s4, 0x1D0($sp)
    ctx->pc = 0x1787c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 464)));
    // 0x1787cc: 0xdfb501d8  ld          $s5, 0x1D8($sp)
    ctx->pc = 0x1787ccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 472)));
    // 0x1787d0: 0xdfb601e0  ld          $s6, 0x1E0($sp)
    ctx->pc = 0x1787d0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x1787d4: 0xdfb701e8  ld          $s7, 0x1E8($sp)
    ctx->pc = 0x1787d4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x1787d8: 0xdfbe01f0  ld          $fp, 0x1F0($sp)
    ctx->pc = 0x1787d8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x1787dc: 0xdfbf01f8  ld          $ra, 0x1F8($sp)
    ctx->pc = 0x1787dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x1787e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1787E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1787E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1787E0u;
            // 0x1787e4: 0x27bd0200  addiu       $sp, $sp, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1783F0u: goto label_1783f0;
            case 0x17840Cu: goto label_17840c;
            case 0x178418u: goto label_178418;
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178558u: goto label_178558;
            case 0x17856Cu: goto label_17856c;
            case 0x178574u: goto label_178574;
            case 0x178588u: goto label_178588;
            case 0x1785FCu: goto label_1785fc;
            case 0x178610u: goto label_178610;
            case 0x17861Cu: goto label_17861c;
            case 0x178628u: goto label_178628;
            case 0x178638u: goto label_178638;
            case 0x178648u: goto label_178648;
            case 0x178654u: goto label_178654;
            case 0x178660u: goto label_178660;
            case 0x17866Cu: goto label_17866c;
            case 0x178760u: goto label_178760;
            case 0x178778u: goto label_178778;
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178828u: goto label_178828;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            case 0x1788CCu: goto label_1788cc;
            case 0x1788E0u: goto label_1788e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1787E8u;
    // 0x1787e8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1787e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1787ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1787ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1787f0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1787f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1787f4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1787f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1787f8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1787f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1787fc: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x1787fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178800: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x178800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x178804: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x178804u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178808: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x178808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17880c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x17880cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178810: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x178810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x178814: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x178814u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178818: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x178818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17881c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x17881cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x178820: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x178820u;
    SET_GPR_U32(ctx, 31, 0x178828u);
    ctx->pc = 0x178824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178820u;
            // 0x178824: 0x26301cc0  addiu       $s0, $s1, 0x1CC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 7360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178828u; }
        if (ctx->pc != 0x178828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178828u; }
        if (ctx->pc != 0x178828u) { return; }
    }
    ctx->pc = 0x178828u;
label_178828:
    // 0x178828: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x178828u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17882c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17882cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178830: 0x34a50192  ori         $a1, $a1, 0x192
    ctx->pc = 0x178830u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)402);
    // 0x178834: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x178834u;
    {
        const bool branch_taken_0x178834 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178834u;
            // 0x178838: 0x24030008  addiu       $v1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178834) {
            ctx->pc = 0x178868u;
            goto label_178868;
        }
    }
    ctx->pc = 0x17883Cu;
    // 0x17883c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17883cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178840: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178844: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178848: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x178848u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17884c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17884cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178850: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178850u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178854: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x178854u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178858: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x178858u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17885c: 0x805a704  j           func_169C10
    ctx->pc = 0x17885Cu;
    ctx->pc = 0x178860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17885Cu;
            // 0x178860: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178864u;
    // 0x178864: 0x0  nop
    ctx->pc = 0x178864u;
    // NOP
label_178868:
    // 0x178868: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x178868u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17886c: 0x1643000e  bne         $s2, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x17886Cu;
    {
        const bool branch_taken_0x17886c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 3));
        ctx->pc = 0x178870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17886Cu;
            // 0x178870: 0x8e020008  lw          $v0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17886c) {
            ctx->pc = 0x1788A8u;
            goto label_1788a8;
        }
    }
    ctx->pc = 0x178874u;
    // 0x178874: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x178874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178878: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178878u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17887c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17887cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x178880: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178880u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178884: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178884u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178888: 0x34a50602  ori         $a1, $a1, 0x602
    ctx->pc = 0x178888u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1538);
    // 0x17888c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17888cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178890: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x178890u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178894: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178894u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178898: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x178898u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17889c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17889cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1788a0: 0x805a704  j           func_169C10
    ctx->pc = 0x1788A0u;
    ctx->pc = 0x1788A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1788A0u;
            // 0x1788a4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1788A8u;
label_1788a8:
    // 0x1788a8: 0x168100  sll         $s0, $s6, 4
    ctx->pc = 0x1788a8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 22), 4));
    // 0x1788ac: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x1788acu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788b0: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x1788b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1788b4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1788b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788b8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1788b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1788bc: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x1788bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1788c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788c4: 0xc05e318  jal         func_178C60
    ctx->pc = 0x1788C4u;
    SET_GPR_U32(ctx, 31, 0x1788CCu);
    ctx->pc = 0x1788C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1788C4u;
            // 0x1788c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178C60u;
    if (runtime->hasFunction(0x178C60u)) {
        auto targetFn = runtime->lookupFunction(0x178C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788CCu; }
        if (ctx->pc != 0x1788CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178C60_0x178c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788CCu; }
        if (ctx->pc != 0x1788CCu) { return; }
    }
    ctx->pc = 0x1788CCu;
label_1788cc:
    // 0x1788cc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1788ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1788d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d4: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1788d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d8: 0xc059bc6  jal         func_166F18
    ctx->pc = 0x1788D8u;
    SET_GPR_U32(ctx, 31, 0x1788E0u);
    ctx->pc = 0x1788DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1788D8u;
            // 0x1788dc: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166F18u;
    if (runtime->hasFunction(0x166F18u)) {
        auto targetFn = runtime->lookupFunction(0x166F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788E0u; }
        if (ctx->pc != 0x1788E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F18_0x166f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788E0u; }
        if (ctx->pc != 0x1788E0u) { return; }
    }
    ctx->pc = 0x1788E0u;
label_1788e0:
    // 0x1788e0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1788e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1788e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1788e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1788e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1788ec: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1788ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1788f0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1788f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1788f4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1788f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1788f8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1788f8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1788fc: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1788fcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178900: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x178900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x178904: 0x3e00008  jr          $ra
    ctx->pc = 0x178904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178904u;
            // 0x178908: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1783F0u: goto label_1783f0;
            case 0x17840Cu: goto label_17840c;
            case 0x178418u: goto label_178418;
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178558u: goto label_178558;
            case 0x17856Cu: goto label_17856c;
            case 0x178574u: goto label_178574;
            case 0x178588u: goto label_178588;
            case 0x1785FCu: goto label_1785fc;
            case 0x178610u: goto label_178610;
            case 0x17861Cu: goto label_17861c;
            case 0x178628u: goto label_178628;
            case 0x178638u: goto label_178638;
            case 0x178648u: goto label_178648;
            case 0x178654u: goto label_178654;
            case 0x178660u: goto label_178660;
            case 0x17866Cu: goto label_17866c;
            case 0x178760u: goto label_178760;
            case 0x178778u: goto label_178778;
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178828u: goto label_178828;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            case 0x1788CCu: goto label_1788cc;
            case 0x1788E0u: goto label_1788e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17890Cu;
    // 0x17890c: 0x0  nop
    ctx->pc = 0x17890cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

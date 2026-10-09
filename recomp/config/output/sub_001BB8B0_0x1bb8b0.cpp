#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB8B0
// Address: 0x1bb8b0 - 0x1bba80
void sub_001BB8B0_0x1bb8b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB8B0_0x1bb8b0");
#endif

    switch (ctx->pc) {
        case 0x1bb920u: goto label_1bb920;
        case 0x1bb92cu: goto label_1bb92c;
        default: break;
    }

    ctx->pc = 0x1bb8b0u;

    // 0x1bb8b0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb8b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb8b4: 0xa0206650  sb          $zero, 0x6650($at)
    ctx->pc = 0x1bb8b4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bb8b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb8b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb8bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB8BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB8C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB8BCu;
            // 0x1bb8c0: 0xac206654  sw          $zero, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB920u: goto label_1bb920;
            case 0x1BB92Cu: goto label_1bb92c;
            case 0x1BB934u: goto label_1bb934;
            case 0x1BB95Cu: goto label_1bb95c;
            case 0x1BB974u: goto label_1bb974;
            case 0x1BB990u: goto label_1bb990;
            case 0x1BB9ECu: goto label_1bb9ec;
            case 0x1BBA08u: goto label_1bba08;
            case 0x1BBA70u: goto label_1bba70;
            case 0x1BBA74u: goto label_1bba74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB8C4u;
    // 0x1bb8c4: 0x0  nop
    ctx->pc = 0x1bb8c4u;
    // NOP
    // 0x1bb8c8: 0x0  nop
    ctx->pc = 0x1bb8c8u;
    // NOP
    // 0x1bb8cc: 0x0  nop
    ctx->pc = 0x1bb8ccu;
    // NOP
    // 0x1bb8d0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb8d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb8d4: 0x8c226654  lw          $v0, 0x6654($at)
    ctx->pc = 0x1bb8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26196)));
    // 0x1bb8d8: 0x38420063  xori        $v0, $v0, 0x63
    ctx->pc = 0x1bb8d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)99);
    // 0x1bb8dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB8DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB8E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB8DCu;
            // 0x1bb8e0: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB920u: goto label_1bb920;
            case 0x1BB92Cu: goto label_1bb92c;
            case 0x1BB934u: goto label_1bb934;
            case 0x1BB95Cu: goto label_1bb95c;
            case 0x1BB974u: goto label_1bb974;
            case 0x1BB990u: goto label_1bb990;
            case 0x1BB9ECu: goto label_1bb9ec;
            case 0x1BBA08u: goto label_1bba08;
            case 0x1BBA70u: goto label_1bba70;
            case 0x1BBA74u: goto label_1bba74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB8E4u;
    // 0x1bb8e4: 0x0  nop
    ctx->pc = 0x1bb8e4u;
    // NOP
    // 0x1bb8e8: 0x0  nop
    ctx->pc = 0x1bb8e8u;
    // NOP
    // 0x1bb8ec: 0x0  nop
    ctx->pc = 0x1bb8ecu;
    // NOP
    // 0x1bb8f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb8f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb8f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb8f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb8f8: 0x90830008  lbu         $v1, 0x8($a0)
    ctx->pc = 0x1bb8f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1bb8fc: 0x1460000d  bnez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1BB8FCu;
    {
        const bool branch_taken_0x1bb8fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB8FCu;
            // 0x1bb900: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb8fc) {
            ctx->pc = 0x1BB934u;
            goto label_1bb934;
        }
    }
    ctx->pc = 0x1BB904u;
    // 0x1bb904: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1bb904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bb908: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bb908u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb90c: 0xa0820008  sb          $v0, 0x8($a0)
    ctx->pc = 0x1bb90cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 8), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bb910: 0x24060024  addiu       $a2, $zero, 0x24
    ctx->pc = 0x1bb910u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1bb914: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb914u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb918: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BB918u;
    SET_GPR_U32(ctx, 31, 0x1BB920u);
    ctx->pc = 0x1BB91Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB918u;
            // 0x1bb91c: 0x24846620  addiu       $a0, $a0, 0x6620 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB920u; }
        if (ctx->pc != 0x1BB920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB920u; }
        if (ctx->pc != 0x1BB920u) { return; }
    }
    ctx->pc = 0x1BB920u;
label_1bb920:
    // 0x1bb920: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x1bb920u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1bb924: 0xc06eea0  jal         func_1BBA80
    ctx->pc = 0x1BB924u;
    SET_GPR_U32(ctx, 31, 0x1BB92Cu);
    ctx->pc = 0x1BB928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB924u;
            // 0x1bb928: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BBA80u;
    if (runtime->hasFunction(0x1BBA80u)) {
        auto targetFn = runtime->lookupFunction(0x1BBA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB92Cu; }
        if (ctx->pc != 0x1BB92Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BBA80_0x1bba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB92Cu; }
        if (ctx->pc != 0x1BB92Cu) { return; }
    }
    ctx->pc = 0x1BB92Cu;
label_1bb92c:
    // 0x1bb92c: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1BB92Cu;
    {
        const bool branch_taken_0x1bb92c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB92Cu;
            // 0x1bb930: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb92c) {
            ctx->pc = 0x1BBA74u;
            goto label_1bba74;
        }
    }
    ctx->pc = 0x1BB934u;
label_1bb934:
    // 0x1bb934: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bb934u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb938: 0x90246620  lbu         $a0, 0x6620($at)
    ctx->pc = 0x1bb938u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26144)));
    // 0x1bb93c: 0x1083002b  beq         $a0, $v1, . + 4 + (0x2B << 2)
    ctx->pc = 0x1BB93Cu;
    {
        const bool branch_taken_0x1bb93c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BB940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB93Cu;
            // 0x1bb940: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb93c) {
            ctx->pc = 0x1BB9ECu;
            goto label_1bb9ec;
        }
    }
    ctx->pc = 0x1BB944u;
    // 0x1bb944: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB944u;
    {
        const bool branch_taken_0x1bb944 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BB948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB944u;
            // 0x1bb948: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb944) {
            ctx->pc = 0x1BB95Cu;
            goto label_1bb95c;
        }
    }
    ctx->pc = 0x1BB94Cu;
    // 0x1bb94c: 0x10800048  beqz        $a0, . + 4 + (0x48 << 2)
    ctx->pc = 0x1BB94Cu;
    {
        const bool branch_taken_0x1bb94c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb94c) {
            ctx->pc = 0x1BBA70u;
            goto label_1bba70;
        }
    }
    ctx->pc = 0x1BB954u;
    // 0x1bb954: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1BB954u;
    {
        const bool branch_taken_0x1bb954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb954) {
            ctx->pc = 0x1BBA70u;
            goto label_1bba70;
        }
    }
    ctx->pc = 0x1BB95Cu;
label_1bb95c:
    // 0x1bb95c: 0x8c236624  lw          $v1, 0x6624($at)
    ctx->pc = 0x1bb95cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26148)));
    // 0x1bb960: 0x18600004  blez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BB960u;
    {
        const bool branch_taken_0x1bb960 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x1bb960) {
            ctx->pc = 0x1BB974u;
            goto label_1bb974;
        }
    }
    ctx->pc = 0x1BB968u;
    // 0x1bb968: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1bb968u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bb96c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb96cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb970: 0xac236624  sw          $v1, 0x6624($at)
    ctx->pc = 0x1bb970u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26148), GPR_U32(ctx, 3));
label_1bb974:
    // 0x1bb974: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb974u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb978: 0x8c256624  lw          $a1, 0x6624($at)
    ctx->pc = 0x1bb978u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26148)));
    // 0x1bb97c: 0x14a00004  bnez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BB97Cu;
    {
        const bool branch_taken_0x1bb97c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB97Cu;
            // 0x1bb980: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb97c) {
            ctx->pc = 0x1BB990u;
            goto label_1bb990;
        }
    }
    ctx->pc = 0x1BB984u;
    // 0x1bb984: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb984u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb988: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1BB988u;
    {
        const bool branch_taken_0x1bb988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB988u;
            // 0x1bb98c: 0xa0206620  sb          $zero, 0x6620($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 26144), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb988) {
            ctx->pc = 0x1BBA70u;
            goto label_1bba70;
        }
    }
    ctx->pc = 0x1BB990u;
label_1bb990:
    // 0x1bb990: 0x51a00  sll         $v1, $a1, 8
    ctx->pc = 0x1bb990u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1bb994: 0x8c246628  lw          $a0, 0x6628($at)
    ctx->pc = 0x1bb994u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26152)));
    // 0x1bb998: 0x652823  subu        $a1, $v1, $a1
    ctx->pc = 0x1bb998u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1bb99c: 0xa4001a  div         $zero, $a1, $a0
    ctx->pc = 0x1bb99cu;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bb9a0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9a4: 0x8c236634  lw          $v1, 0x6634($at)
    ctx->pc = 0x1bb9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26164)));
    // 0x1bb9a8: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1bb9a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1bb9ac: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9b0: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1bb9b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1bb9b4: 0xac236634  sw          $v1, 0x6634($at)
    ctx->pc = 0x1bb9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26164), GPR_U32(ctx, 3));
    // 0x1bb9b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9bc: 0x8c236634  lw          $v1, 0x6634($at)
    ctx->pc = 0x1bb9bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26164)));
    // 0x1bb9c0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9c4: 0x2012  mflo        $a0
    ctx->pc = 0x1bb9c4u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x1bb9c8: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1bb9c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1bb9cc: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1bb9ccu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1bb9d0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1bb9d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1bb9d4: 0xac236634  sw          $v1, 0x6634($at)
    ctx->pc = 0x1bb9d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26164), GPR_U32(ctx, 3));
    // 0x1bb9d8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9dc: 0x8c236634  lw          $v1, 0x6634($at)
    ctx->pc = 0x1bb9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26164)));
    // 0x1bb9e0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9e4: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1BB9E4u;
    {
        const bool branch_taken_0x1bb9e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB9E4u;
            // 0x1bb9e8: 0xac236640  sw          $v1, 0x6640($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26176), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb9e4) {
            ctx->pc = 0x1BBA70u;
            goto label_1bba70;
        }
    }
    ctx->pc = 0x1BB9ECu;
label_1bb9ec:
    // 0x1bb9ec: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb9ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb9f0: 0x8c236624  lw          $v1, 0x6624($at)
    ctx->pc = 0x1bb9f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26148)));
    // 0x1bb9f4: 0x18600004  blez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BB9F4u;
    {
        const bool branch_taken_0x1bb9f4 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x1bb9f4) {
            ctx->pc = 0x1BBA08u;
            goto label_1bba08;
        }
    }
    ctx->pc = 0x1BB9FCu;
    // 0x1bb9fc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1bb9fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bba00: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba04: 0xac236624  sw          $v1, 0x6624($at)
    ctx->pc = 0x1bba04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26148), GPR_U32(ctx, 3));
label_1bba08:
    // 0x1bba08: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba0c: 0x8c266628  lw          $a2, 0x6628($at)
    ctx->pc = 0x1bba0cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26152)));
    // 0x1bba10: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba14: 0x8c246624  lw          $a0, 0x6624($at)
    ctx->pc = 0x1bba14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26148)));
    // 0x1bba18: 0xc42823  subu        $a1, $a2, $a0
    ctx->pc = 0x1bba18u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1bba1c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba20: 0x52200  sll         $a0, $a1, 8
    ctx->pc = 0x1bba20u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1bba24: 0x8c236634  lw          $v1, 0x6634($at)
    ctx->pc = 0x1bba24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26164)));
    // 0x1bba28: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x1bba28u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1bba2c: 0x86001a  div         $zero, $a0, $a2
    ctx->pc = 0x1bba2cu;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bba30: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1bba30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1bba34: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba38: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1bba38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1bba3c: 0xac236634  sw          $v1, 0x6634($at)
    ctx->pc = 0x1bba3cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26164), GPR_U32(ctx, 3));
    // 0x1bba40: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba44: 0x8c236634  lw          $v1, 0x6634($at)
    ctx->pc = 0x1bba44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26164)));
    // 0x1bba48: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba4c: 0x2012  mflo        $a0
    ctx->pc = 0x1bba4cu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x1bba50: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1bba50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1bba54: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1bba54u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1bba58: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1bba58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1bba5c: 0xac236634  sw          $v1, 0x6634($at)
    ctx->pc = 0x1bba5cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26164), GPR_U32(ctx, 3));
    // 0x1bba60: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba64: 0x8c236634  lw          $v1, 0x6634($at)
    ctx->pc = 0x1bba64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26164)));
    // 0x1bba68: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bba68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bba6c: 0xac236640  sw          $v1, 0x6640($at)
    ctx->pc = 0x1bba6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26176), GPR_U32(ctx, 3));
label_1bba70:
    // 0x1bba70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bba70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1bba74:
    // 0x1bba74: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBA74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBA74u;
            // 0x1bba78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB920u: goto label_1bb920;
            case 0x1BB92Cu: goto label_1bb92c;
            case 0x1BB934u: goto label_1bb934;
            case 0x1BB95Cu: goto label_1bb95c;
            case 0x1BB974u: goto label_1bb974;
            case 0x1BB990u: goto label_1bb990;
            case 0x1BB9ECu: goto label_1bb9ec;
            case 0x1BBA08u: goto label_1bba08;
            case 0x1BBA70u: goto label_1bba70;
            case 0x1BBA74u: goto label_1bba74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBA7Cu;
    // 0x1bba7c: 0x0  nop
    ctx->pc = 0x1bba7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

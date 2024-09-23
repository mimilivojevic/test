# Contributing to [INSERT PROJECT NAME]

The [INSERT PROJECT NAME] team encourages community feedback and contributions.
Thank you for your interest in making [INSERT PROJECT NAME] better! There are several
ways you can get involved.

If you are looking for a good way to contribute to the project, please:

* take a look at a [Pull Request template](PULL_REQUEST_TEMPLATE.md) to get yourself
started.


## Finding issues you can help with

Looking for something to work on?
Issues marked [`good first issue`]
are a good place to start.

You can also check the [`help wanted`]
tag to find other issues to help with. If you're interested in working on a fix,
leave a comment to let everyone know and to help avoid duplicated effort from others.

## Contributions we accept

We highly appreciate any contributions that help us improve the end product, with
a high emphasis being put on any bug fixes you can manage to create and direct
improvements which address the top issues reported by Calculator users. Some general
guidelines:

### DOs

* **DO** create one pull request per Issue, and ensure that the Issue is linked
in the pull request. You can follow the [Pull Request Template](PULL_REQUEST_TEMPLATE.md)
for this.

* **DO** follow our [Coding and Style](#style-guidelines) guidelines, and keep code
changes as small as possible.

* **DO** include corresponding tests whenever possible.

* **DO** check for additional occurrences of the same problem in other parts of the
codebase before submitting your PR.

* **DO** link the issue you are addressing in the pull request.

* **DO** write a good description for your pull request. More detail is better.
Describe *why* the change is being made and *why* you have chosen a particular solution.
Describe any manual testing you performed to validate your change.

### DO NOTs

* **DO NOT** merge multiple changes into one PR unless they have the same root cause.
* **DO NOT** merge directly into the master branch.

> Submitting a pull request for an approved Issue is not a guarantee it will be approved.
> The change must meet our high bar for code quality, architecture and performance.

## Making changes to the code

### Preparing your development environment

To learn how to build the code and run tests, follow the instructions in the [README](README.md).

### Style guidelines

The code in this project uses several different coding styles, depending on the
age and history of the code. Please attempt to match the style of surrounding
code as much as possible.

### Code formatting

***Run clang-format***

Use the following commands from the project's root directory to run clang-format
(must be installed on the host system).

**1. Run the CMake target for `clang-format`:**

```bash
cmake --build build --target clang-format
```

**2. Using clang-format:**

```bash
# !!! clang-format does not run recursively in subdirectories !!!
# for each .cpp file modified
clang-format -i *.cpp

# for each .h file modified
clang-format -i *.h

# for each .hpp file modified
clang-format -i *.hpp
```

**3. Using TheLartians' Format.cmake:**

```bash
cmake -Htest -Bbuild/test

# view changes
cmake --build build/test --target format

# apply changes
cmake --build build/test --target fix-format
```

### Testing

Your change should include tests to verify new functionality wherever possible.
Code should be structured so that it can be unit tested independently of the UI.
Manual test cases should be used where automated testing is not feasible.

### Git workflow

The core principle of the project, when it comes to Git workflows is that the
`master` branch should always be in a healthy state which is ready for release.
Every commit on master should be deployable on push. To ensure this, pull request
**must not** be made directly on master. **Each change** should either be made in
the **development branch** (named a variation of development, i.e. `dev`) or in a
separate branch, named as a short summary of the change.

If your change is complex, please clean up the branch history before submitting a
pull request. 

When completing a pull request, we will generally squash your changes into a single
commit. After confirming that the change works as intended, the branch *might* be
deleted, in order to prevent branch polluting. Please let us know if your pull request
needs to be merged as separate commits.

### Continuous Integration

For this project, CI 
with workflows found in the [`.github/workflows` folder](.github/workflows). Workflows
are run automatically on every commit made on the master branch, unless told to skip
for that particular commit.

To skip CI runs on a particular commit, include either `[skip ci]` or `[ci skip]`
in the commit message.

```bash
# an example of a commit message that would not trigger CI workflows
git commit -m "my normal commit message [skip ci]"
# or
git commit -m "my normal commit message [ci skip]"
```

## Review process

After submitting a pull request, members of the team will review your code. We will
assign the request to an appropriate reviewer (if applicable). Any member of the
community may participate in the review, but at least one member of the project team
will ultimately approve the request.

Often, multiple iterations or discussions will be needed to responding to feedback
from reviewers. 
to see what the experience might be like.

## Contributor License Agreement

Before we can review and accept a pull request from you, you'll need to sign a
Contributor License Agreement (CLA). The CLA ensures that the community is free
to use your contributions. Signing the CLA is a manual process, and you need to
do it for each pull request made. This is done by checking the boxes in the
[Pull Request Readiness Checklist of a Pull Request](PULL_REQUEST_TEMPLATE.md#Pull-Request-Readiness-Checklist).

### IMPORTANT

***Checking the aforementioned boxes means that you agree to provide your change
and/or code FREE TO USE and SUBJECT TO CHANGES for the entire community!***

You don't need to sign a CLA until you're ready to create a pull request. When your
pull request is created, it is reviewed by a team member which, if the change is
trivial (i.e. you just fixed a typo) will be labelled as `cla-not-required`.
Otherwise, it's classified as `cla-required`, if not already signed.
